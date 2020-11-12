void calc(){

  if(number>=0&&number<=9){

    if(phase==0){
      num1=number;
      phase=1;
    }
    else if(phase==1){
      num1=num1*10;
      num1=num1+number;
    }
    else if(phase==2){
      num2=number;
      phase=3;
    }
    else if(phase==3){
      num2=num2*10;
      num2=num2+number;
    } 
  }
  else if(number=10){ 
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=0;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
    
  }
  else if(number==11){ 
    if(phase=0){
    }
    if(phase=1){
      phase=2;
      calctype=1;
    }
    if(phase=2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
       }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==12){ 
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=2;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
       if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==13){
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=3;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==14){
    if(phase==0){
      
    }
    if(phase==1){
      if(calctype==0){
        result=num1*2;
        phase=3;
      }
      if(calctype==1){
        result=0;
        phase=3;
      }
      if(calctype==2){
        result=num1*num1;
        phase=3;
      }
      if(calctype==3){
        result=1;
        phase=3;
      }
      else{
        errortype=1;
        disperror();
      }
    }
    if(phase==2){
      if(calctype==0){
        result=num1+num2;
        phase=3;
      }
      else if(calctype==1){
        result=num1-num2;
        phase=3;
      }
      else if(calctype==2){
        result=num1*num2;
        phase=3;
      }
      else if(calctype==3){
       if(num2==0){
        errortype=0;
        disperror();
        num2=0;
        phase=1;
       }
       else{
        result=num1/num2;
        num2=0;
        phase=3;
       }
      }
      else{
        errortype=1;
        disperror();
      }
     }
    }
  else if(number==15){

    if(phase==3){
      num1=num2=result=0;
      phase=0;
    }
    else if(phase==2){
      num2=0;
      phase=1;
    }
    else if(phase==1){
      num1=0;
      phase=0;
    }
    else if(phase==0){}
}
}
