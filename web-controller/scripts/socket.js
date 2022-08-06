// this file relies on statuses.js to exist before itself
let meshTelUploading = false;
let socketInterval = null;

const connectToRobot = () => {
  const socket = new WebSocket('ws://192.168.1.195:80'); // esp01 on robot

  // connection opened, send messages to robot
  socket.addEventListener('open', function (event) {
    socket.send('Hello robot!');
 
    // keep connection to esp01 alive
    socketInterval = setInterval(() => {
      socket.send('poll');
    }, 1000);
  });
 
// listen for messages from robot
  socket.addEventListener('message', function (event) {
    const robotMsg = event.data;
    console.log(robotMsg);
  });
 
  socket.addEventListener('close', function (event) {
    clearInterval(socketInterval);
    if (!meshTelUploading) connectToRobot();
 });
}

connectToRobot();