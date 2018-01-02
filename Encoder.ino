void EncoderR() { 
   rightState = digitalRead(rightA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (rightState != rightLState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(rightB) != rightState) { 
       rightCounter ++;
     } else {
       rightCounter --;
     }
   } 
   rightLState = rightState; // Updates the previous state of the outputA with the current state
   
 }

void EncoderL() { 
   leftState = digitalRead(leftA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (leftState != leftLState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(leftB) != leftState) { 
       leftCounter ++;
     } else {
       leftCounter --;
     }
   } 
   leftLState = leftState; // Updates the previous state of the outputA with the current state
   
 }

