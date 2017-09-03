var beginX = 20.0;  // Initial x-coordinate
var beginY = 10.0;  // Initial y-coordinate
var endX = 570.0;   // Final x-coordinate
var endY = 320.0;   // Final y-coordinate
var distX;          // X-axis distance to move
var distY;          // Y-axis distance to move
var exponent = 4;   // Determines the curve
var x = 0.0;        // Current x-coordinate
var y = 0.0;        // Current y-coordinate
var t = 0.01;    // Size of each step along the path
var pct = 0.0;      // Percentage traveled (0.0 to 1.0)

var dir = 1;

function setup() {
  createCanvas(window.innerWidth, window.innerHeight);
  noStroke();
  distX = endX - beginX;
  distY = endY - beginY;
}

function draw() {
  drawMotion(100,200,110, (t*t*t));
} 

function mousePressed() {
  pct = 0.0; 
  beginX = x;
  beginY = y;
  endX = mouseX;
  endY = mouseY;
  distX = endX - beginX;
  distY = endY - beginY;
}

function drawMotion(r,g,b,timing){
  background(0);
  pct += t * dir;
  if (pct <= 0 || pct >= 1) dir *= -1;
  if (pct < 1.0) {
    x = beginX + (pct * distX);
    y = beginY + (pow(pct, exponent) * distY);
  }
  moveX = (1-timing) * x + timing * endX;
  moveY = (1-timing) * y + timing * endY;
  fill(r,g,b);
  ellipse(moveX, moveY, 20, 20);
}