import "./style.css";
import { useState } from "react";

function InfiniteScrollDomApi() {
    const [data, setData] = useState([...new Array(40)]);
    const [loading, setLoading] = useState(false);
    const THRESHOLD = 20;

    function handleScroll(event) {
        const scrollTop = event.target.scrollTop;
        const clientHeight = event.target.clientHeight;
        const scrollHeight = event.target.scrollHeight;

        const remainingScroll = scrollHeight - (clientHeight + scrollTop);

        console.log('remainingScroll -- ', remainingScroll, " || scrollTop -- ", scrollTop, " || clientHeight -- ", clientHeight, " ||  scrollHeight -- ", scrollHeight);

        if (remainingScroll < THRESHOLD && !loading) loadMore();
    }

    function loadMore() {
        setLoading(true);
        setTimeout(() => {
            setData(prev => [...prev, ...new Array(10)]);
            setLoading(false);
        }, 500);
    }

    return (
        <div onScroll={handleScroll} className='scroll-dom-api'>
            {
                data.map((row, index) => {
                    return (
                        <div className="row" key={index}>
                            {index + 1}
                        </div>
                    )
                })
            }
            {loading && <div className="loading">Loading...</div>}
        </div>
    )
}

export default InfiniteScrollDomApi;