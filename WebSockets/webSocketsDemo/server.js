import WebSocket, { WebSocketServer } from 'ws';

const wss = new WebSocketServer({ port: 8080 });

wss.on("connection", (socket, request) => {
    const ip = request.socket.remoteAddress;
    console.log('ip -- ', ip);

    socket.on('message', (rawData) => {
        const message = rawData.toString();
        console.log('received: %s', rawData);

        wss.clients.forEach(client => {
            if (client.readyState === WebSocket.OPEN) {
                client.send(`Server Broadcast: ${message}`)
            }
        })
    });

    socket.on("error", (err) => {
        console.log(`Error: ${err.message}: ${ip}`);
    })

    socket.on("close", () => {
        console.log(`Connection closed: ${ip}`);
    });
})

console.log('Websocket Server is live on ws://localhost:8080');