var ptA = 100;
var ptB = 400;
var moveX = ptA;
var y = 200;
var t = 0;
var dir = 1;
var go = false;

//easing
var outSin = Math.sin(t / 1 * (Math.PI * 0.5));
function setup(){
  one = createCanvas(window.innerWidth, window.innerHeight);
  background(122,183,240);
}

function draw(){
  background(123, 195, 216);
  var spacing = 50;
  drawMotion(spacing, pow(t,5.5), "pow(t,5.5)");
  spacing += 50;
  drawMotion(spacing, t*t*t, "t*t*t");
  spacing += 50;
  drawMotion(spacing, -1 * (Math.sqrt(1 - t * t) - 1), "-1 * (Math.sqrt(1 - t * t) - 1)");
  spacing += 50;
  drawMotion(spacing, -1 / 2 * (Math.cos(Math.PI * t) - 1), "-1 / 2 * (Math.cos(Math.PI * t) - 1)");
  spacing += 50;
  drawMotion(spacing, Math.sin(t / 1 * (Math.PI * 0.5)), "Math.sin(t / 1 * (Math.PI * 0.5))");
  spacing += 50;
  drawMotion(spacing, t, "t");
  
  one.mouseOver(start);
  one.mouseOut(stop);
  
}

//parameters: yoffset, pct
function drawMotion(yoffset, pct, label){
  
  
  t += 0.005 * dir;
  if (t <= 0 || t >= 1) dir *= -1;
  
  //change shape of our motion
  var pct = pct;
  //(1-pct) * A + pct * B
  //moveX = (1-pct) * ptA + pct * ptB;
  if(go){
    moveX = (1-pct) * ptA + pct * ptB;
  }else{
    moveX = ptA;
  }
 
  
 stroke(251,60,127);
 
 line(ptA,yoffset,ptB,yoffset);
 text(label, 410, yoffset);
 fill(251,60,127);
 //strokeWeight(0);
 ellipse(moveX,yoffset,20,20);
}

function start(){
  go = true;
}

function stop(){
  go = false;
}