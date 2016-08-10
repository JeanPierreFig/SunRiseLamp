
PImage img;
Button on_button;  // the button
color c;
int clk = 1; 
boolean generateHex; 
PrintWriter output;

void setup() {
  size(700,700);
  
   selectInput("Select a file to process:", "fileSelected");
 
  // create the button object
  on_button = new Button("Generate hex", width/2.7, height-100, 150, 50);
  
  
}

void fileSelected(File selection) {
  if (selection == null) {
    ;
  } else {
   
     img = loadImage(selection.getAbsolutePath());
  }
}

int i = 0;

void draw() {
 
 

  
  if(generateHex == true){
      image(img, width/4, height/6, width/2, height/2);
      
   if(i < img.height){
    
      c = img.get(20, i);
      fill(c);
      rect(width/2.1,height-200, 50, 50);
      println( String.format("\"%s\",",hex(c, 6)));
     
    
      if(img.height == i){
        
        i=0;
        generateHex = false;
        output.flush(); 
        }
      
    }
    
    i++;
  }
  
  if (on_button.MouseIsOver()) {
  }
  else {
   // hide the square if the mouse cursor is not over the button
   // background(0);
  }
  // draw the button in the window
  on_button.Draw();
  
}

// mouse button clicked
void mousePressed()
{
  if (on_button.MouseIsOver()) {
   
   
    generateHex = true;
    
  
  }
}

// the Button class
class Button {
  String label; // button label
  float x;      // top left corner x position
  float y;      // top left corner y position
  float w;      // width of button
  float h;      // height of button
  
  // constructor
  Button(String labelB, float xpos, float ypos, float widthB, float heightB) {
    label = labelB;
    x = xpos;
    y = ypos;
    w = widthB;
    h = heightB;
  }
  
  void Draw() {
    fill(218);
    stroke(141);
    rect(x, y, w, h, 10);
    textAlign(CENTER, CENTER);
    fill(0);
    text(label, x + (w / 2), y + (h / 2));
    
    
  }
  
  boolean MouseIsOver() {
    if (mouseX > x && mouseX < (x + w) && mouseY > y && mouseY < (y + h)) {
      return true;
    }
    return false;
  }
}