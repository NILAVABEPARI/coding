const explorerData = {
    id: 1,
    name: "root",
    isFolder: true,
    items: [
        {
            id: 2,
            name: "public",
            isFolder: true,
            items: [
                {
                    id: 3,
                    name: "index.js",
                    isFolder: false,
                    items: []
                }
            ]
        },
        {
            id: 4,
            name: "src",
            isFolder: true,
            items: [
                {
                    id: 5,
                    name: "components",
                    isFolder: true,
                    items: [
                        {
                            id: 6,
                            name: "folder.js",
                            isFolder: false,
                            items: []
                        }
                    ]
                },
                {
                    id: 7,
                    name: "data",
                    isFolder: true,
                    items: [
                        {
                            id: 8,
                            name: "folderData.js",
                            isFolder: false,
                            items: []
                        }
                    ]
                },
                {
                    id: 9,
                    name: "App.jsx",
                    isFolder: false,
                    items: []
                },
                {
                    id: 10,
                    name: "App.css",
                    isFolder: false,
                    items: []
                }
            ]
        },
        {
            id: 11,
            name: "package.json",
            isFolder: false,
            items: []
        }
    ]
}



export default explorerData;