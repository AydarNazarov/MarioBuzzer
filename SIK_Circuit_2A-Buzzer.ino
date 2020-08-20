int speakerPin = 10;               //the pin that buzzer is connected to
int led = 13;
char text[] = "O3g1g3g3D1g3A7O2AO31O36D7O2AO33O2gO35c1O32d3C1c3O2AO32g1A2O4cO33G1O3A3g3D1f1d5D5O2AO31O34O2gO35c3d3C1c3O2AO31O31g1A2O4cO33G1A3g3D1f1d1O38A1a1G1F3g3O2bO31c1O3D3c1D1f5A1a1G1F3g1O32O4DO33O4DO31O4DO383A1a1G1O3F3g3O2bO31c1D3c1D1f5O3F5f5D94O32D1D3D3D1f3g1D3c1O3O2AO37D1D3D3D1f1g3O395D1D3D3D1O3f3g1D3c1O2AO37D1D3O3D3D1g3A7O2AO37O3D5O2AO35O2gO35c3d3O3C1c3O2AO32g1A2O4cO33G1A3g1O32D1f1D5D5O2AO35O2gO31O34c3d3C1c3O2AO32g1A2O3O4cO33G1A3g3D1g1d5g1O3D3O2AO35O2AO33c1G3G1c3O34d2O4cO31O4cO32O4cO32A1G2g1D3O3c1O2AO37g1D3O2AO35O2AO33O3c1f3f1c7d1G3G1G1O31g1f2D1O2AO33g1D7g1D1O32O2AO35O2AO33c1G3G1c5O32d2O4cO31O4cO32O4cO32A1G2g1D3c1O3O2AO37g1D3O2AO35O2bO33c1O3f3f1c7d1G3G1G2gO31f2D5g1D7D5O2A5g3O3DO27A3g3O32c3d3C1c3O2AO32g1A2O4cO31O32G1A3g3D1f1d5D3O32O2AO35O2gO35c3d3C1c1O32O2AO32g1A2O4cO33G1A3g3D1O3f1d9A1a1G1F3g3O3O2bO31c1D3c1D1f5A1a1G1F1O32g3O4DO33O4DO31O4DO392A1O3a1G1F3g3O2bO31c1D3c1D1f1O34F5f5D9O36D1D3D3D1f3g1D1O32c1O2AO37D1D3D3D1f1O3g98D1D3D1O32D1f3g1D3c1O2AO37D1O3D3D3D1g3A7O2AO33O34D5O2AO35O2gO35c3O3d3C1c3O2AO32g1A2O4cO33G1A1O32g3D1f1D5D5O2AO33O32O2gO35c3d3C1c3O2AO32gO31A2O4cO33G1A3g3D1g1d3O32g1D3O2AO35O2bO33c1G3G1O3c7d2O4cO31O4cO32O4cO32A1G2g1O3D3c1O2AO37g1D3O2AO35O3O2bO33c1f3f1c7d1G3O3G1G2g1f2D1O2AO33g1D7O3g1D3O2AO35O2bO33c1G3G1c1O36d2O4cO31O4cO32O4cO32A11G2g1D1O32c1O2AO37g1D3O2AO35O2bO31O32c1f3f1c7d1G3G1O3G2g1f2D5g1D7D1O34O2AO35O2gO33c2d1c2O2bO32CO21b2A1G1A";
int frequencies[8][14] = {{32,34,36,38,41,43,46,49,52,55,58,61,0},
                         {65,69,73,77,82,87,92,98,104,110,116,123,0},
                         {130,138,146,155,164,174,185,196,208,220,233,246,0},
                         {261,277,293,311,329,349,369,392,415,440,466,493,0},
                         {523,554,587,622,659,698,739,784,830,880,932,987,0},
                         {1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,0},
                         {2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,0},
                         {4186,4435,4699,4978,5274,5588,5920,6272,6645,7040,7459,7902,0}};
int numNotes = 13;  
char notes[] = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b', 'B', '-'}; 
int currentOctave = 0;


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
}

void loop()
{  
  
  for(int k = 0; k < strlen(text); k++){
    if(text[k] == 'O'){
      k++;
      currentOctave = text[k] - '0';
    }
    else if(text[k] >= '1' && text[k] <= '9'){
      for(int j = 0; j < (text[k] - '0'); j++){
        play('-', currentOctave,1);
      }
    }
    else{
      play(text[k], currentOctave,1);
      
    }
  }


  
 
 while (true) {}     
}

  
void play( char note, int octave, int beats)
{

  int currentFrequency = 0;    
  int beatLength = 40;  
  for (int i = 0; i < numNotes; i++)  
  {
    if (notes[i] == note)             
    {
      currentFrequency = frequencies[octave][i];   
    }
  }

  
  tone(speakerPin, currentFrequency, beats * beatLength);
  if (currentFrequency != 0){
    digitalWrite(13, HIGH);
  }
  delay(beats * beatLength);
  if (currentFrequency != 0){
    digitalWrite(13, LOW);
  } 
  delay(20);                 
}
