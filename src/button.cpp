#include "button.h" 

  Button::Button() { }
  Button::Button(String name, uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, String buttonText, uint16_t textOffsetLeft, uint16_t textOffsetTop)
  :name{name},x0{x0},y0{y0},w{w},h{h},buttonText{buttonText},textOffsetLeft{textOffsetLeft},textOffsetTop{textOffsetTop} {
   this->pressed = false;
   this->currentStatus = "none";
  };
  
  void Button::render() { 
      if(this->getName() == "startGrowBtn") {
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);

        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_OLIVE);

        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);

        tft.print(buttonText);
      }
    
      if(this->getName() == "dayCounterBtn") {}
    
      if(this->getName() == "cancelScreenOkBtn") {
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);

        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_OLIVE);

        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);

        tft.print(buttonText);      
      }
    
      if(this->getName() == "terminateBtn") {
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);

        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_RED);

        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);

        tft.print(buttonText);      
      }
    
      if(this->getName() == "terminateYesBtn") {
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);

        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_RED);

        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);

        tft.print(buttonText);      
      } 
    
      if(this->getName() == "terminateNoBtn") {
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);

        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_GREEN);

        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);

        tft.print(buttonText);      
      }
    
      if(this->getName() == "timerBtn") {}
    
      if(this->getName() == "timerUpBtn") {
        tft.fillTriangle(240, 95, 260, 55, 280, 95, ILI9341_RED);
      }
    
      if(this->getName() == "timerDownBtn") {
        tft.fillTriangle(240, 130, 260, 170, 280, 130, ILI9341_RED);    
      } 
    
      if(this->getName() == "timerOkBtn") {
        
        tft.drawRect(x0,y0,w,h,ILI9341_WHITE);
        tft.fillRect(x0+1,y0+1,w-2,h-2,ILI9341_OLIVE);
        tft.setCursor(x0 + textOffsetLeft,y0 + textOffsetTop);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);
        tft.print(buttonText); 
        
      }
  
  }
  
  void Button::renderPressed() {
    
    if(this->getName() == "startGrowBtn") {
      tft.drawRect(x0,y0,w,h,ILI9341_RED);
    }
    
    if(this->getName() == "timerUpBtn") {
      tft.fillTriangle(240, 95, 260, 55, 280, 95, ILI9341_WHITE);
    }
    if(this->getName() == "timerDownBtn") {
        tft.fillTriangle(240, 130, 260, 170, 280, 130, ILI9341_WHITE);    
    }            
    
    
  }
  String Button::getName() {
    return this->name;
  };
  uint16_t Button::getx0() {
    return this->x0;
  };
   uint16_t Button::gety0() {
    return this->y0;
  };
   uint16_t Button::getW() {
    return this->w;
  };
   uint16_t Button::getH() {
    return this->h;
  };
   String Button::getButtonText() {
    return this->buttonText;
  };
   uint16_t Button::getTextOffsetLeft() {
    return this->textOffsetLeft;
  };
   uint16_t Button::getTextOffsetTop() {
    return this->textOffsetTop;
  };
  
  bool Button::isPressed(int x,int y) {
    
   if( (x > this->getx0() && x < (this->getx0()+this->getW()) ) && (y > this->gety0() && (y < (this->gety0()+this->getH()) ) )  ) {
     
     this->renderPressed();
     return true;
     
   } else {
     if(this->pressed) {
       this->setStatus("none");
     }
    return false;
   }
 }
    
    void Button::setStatus(String status) {
      this->currentStatus = status;
    }
    
    String Button::getStatus() {
      return this->currentStatus;
    }