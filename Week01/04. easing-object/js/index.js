var skyColor = "#cbe7f2";


//sun 
var beginX = window.innerWidth/4;  // Initial x-coordinate
var beginY = window.innerHeight/4 + 40;  // Initial y-coordinate
var endX = window.innerWidth/1.5;   // Final x-coordinate
var endY = window.innerHeight/2;   // Final y-coordinate
var distX;          // X-axis distance to move
var distY;          // Y-axis distance to move
var exponent = 4;   // Determines the curve
var x = 0.0;        // Current x-coordinate
var y = 0.0;        // Current y-coordinate
var t = 0.01;    // Size of each step along the path
var pct = 0.0;      // Percentage traveled (0.0 to 1.0)

var dir = 1;

//easing
var outSin = Math.sin(t / 1 * (Math.PI * 0.5));
function setup(){
  //sun
  distX = endX - beginX;
  distY = endY - beginY;
}

function draw(){
  one = createCanvas(window.innerWidth, window.innerHeight);
  background(123, 195, 216);
   
  picturebackground();
  one.mouseOver(over); 
  one.mouseOut(out);
  
  //sun
  drawMotion(242, 214, 31, t*t*t);
  pictureframe();
  
}

function picturebackground(){
  
  //left string
  stroke(60, 67, 73);
  strokeWeight(2);
  line(window.innerWidth/2, window.innerHeight/9, window.innerWidth/3, window.innerHeight/4);
  //right string
  stroke(60, 67, 73);
  strokeWeight(2);
  line(window.innerWidth/2, window.innerHeight/9, window.innerWidth/1.5, window.innerHeight/4);
  //nail
  stroke(255);
  strokeWeight(2);
  fill(60, 67, 73);
  ellipse(window.innerWidth/2, window.innerHeight/9, 10, 10);
  //sky
  fill("#cbe7f2");
  rect(window.innerWidth/4,window.innerHeight/4,window.innerWidth/2,window.innerHeight/2);
  noStroke();
  // //sky overlay
  // fill(153, 98, 64, 1);
  // rect(window.innerWidth/4,window.innerHeight/4,window.innerWidth/2,window.innerHeight/2);
  // noStroke();

}
 
function pictureframe(){
   //left hill
  fill(16, 119, 16);
  arc(window.innerWidth/4, window.innerHeight/1.5+40, window.innerWidth/1.6, window.innerHeight/2, PI+HALF_PI, TWO_PI);
  //right hill
  fill(20, 150, 20);
  arc(window.innerWidth/1.35, window.innerHeight/1.5+40, window.innerWidth/1.25, window.innerHeight/1.75, PI, PI+HALF_PI);
  
  
    // set fill to transparent
  fill(153, 98, 64, 0);
  //inner frame
  stroke(127, 147, 165);
  strokeWeight(40);
  rect(window.innerWidth/4,window.innerHeight/4,window.innerWidth/2,window.innerHeight/2);
  //outter frame
  stroke(60, 67, 73);
  strokeWeight(10);
  rect(window.innerWidth/4 - 20,window.innerHeight/4-20,window.innerWidth/2+40,window.innerHeight/2+40);
}

function over(){
  var r = 0;
  var g = 0;
  var b = 0;
  
  skyColor="rgb(0,0,0)";
}

function out(){
  skyColor="rgb(203, 231, 242)";
}

//sun
function drawMotion(r,g,b,timing){
  pct += t * dir;
  if (pct <= 0 || pct >= 1) dir *= -1;
  if (pct < 1.0) {
    x = beginX + (pct * distX);
    y = beginY + (pow(pct, exponent) * distY);
  }
  moveX = (1-timing) * x + timing * endX;
  moveY = (1-timing) * y + timing * endY;
  noStroke(0,0,0);
  fill(r,g,b);
  ellipse(moveX, moveY, 20, 20);
}