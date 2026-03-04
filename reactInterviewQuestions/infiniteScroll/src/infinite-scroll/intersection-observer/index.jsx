import { useEffect, useRef, useState } from 'react';
import './style.css'

const InfiniteScrollIntersectionDom = () => {
    const [data, setData] = useState([...new Array(60)]);
    const [loading, setLoading] = useState(false);

    const refList = useRef([]);

    function loadMore() {
        setLoading(true);
        setTimeout(() => {
            setData(prev => [...prev, ...new Array(10)]);
            setLoading(false);
        }, 500);
    }

    useEffect(() => {
        const observer = new IntersectionObserver(function (entries) {
            if (entries[0].isIntersecting) {
                observer.unobserve(entries[0].target);
                loadMore();
            }
        });

        const lastElement = refList.current[refList.current.length - 1];
        observer.observe(lastElement);

        return () => {
            observer.disconnect();
        }
    }, [data.length])

    return (
        <div className='scroll-intersection-observer'>
            {
                data.map((row, index) => {
                    return (
                        <div ref={(el) => (refList.current[index] = el)} className="row" key={index}>
                            {index + 1}
                        </div>
                    )
                })
            }
            {loading && <div className="loading">Loading...</div>}
        </div>
    )
}

export default InfiniteScrollIntersectionDom