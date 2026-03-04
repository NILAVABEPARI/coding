import { useState } from "react";

function Folder({ explorer }) {
    const [showTree, setShowTree] = useState(false);
    const [showInput, setShowInput] = useState({
        visible: false,
        isFolder: null
    });

    const handleNewFolderFile = (e, isFolder) => {
        e.stopPropagation();

        setShowInput({
            visible: true,
            isFolder
        })
    }

    if (explorer.isFolder) {
        return (
            <div>
                <div className="folder" onClick={() => setShowTree(!showTree)}>
                    <span>📁 {explorer.name}</span>

                    <div>
                        <button onClick={(e) => handleNewFolderFile(e, true)}>Folder +</button>
                        <button onClick={(e) => handleNewFolderFile(e, false)}>File +</button>
                    </div>
                </div>
                <div style={{ paddingLeft: 15, display: showTree ? "block" : "none" }}>
                    {explorer.items.map((exp) => {
                        return (
                            <Folder explorer={exp} key={exp.id} />
                        )
                    })}
                </div>
            </div>
        )
    } else {
        return (
            <span className="file">📄 {explorer.name}</span>
        )
    }

}

export default Folder;