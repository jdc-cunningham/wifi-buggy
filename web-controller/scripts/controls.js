const dpadForward = document.getElementById('forward');
const dpadLeft = document.getElementById('left');
const dpadRight = document.getElementById('right');
const dpadBackward = document.getElementById('back');

const dpadBtns = [dpadForward, dpadLeft, dpadRight, dpadBackward];
const commLookup = {
  'forward': 'm_f',
  'left': 'm_l',
  'right': 'm_r',
  'backward': 'm_b',
  'stop': 'm_s'
};

let activeDirection = '';

dpadBtns.forEach(dpadBtn => dpadBtn.addEventListener('click', (e) => {
  const whichDir = e.target.getAttribute('id');

  activeDirection = whichDir;
  socket.send(commLookup[activeDirection]);
}));