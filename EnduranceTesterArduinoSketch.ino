unsigned long start        = 0;
unsigned long max_seconds  = 10;
unsigned long  i           = 2; // Start at 2
//unsigned long  i           = 4294966583; // End in sometime (for testing)
unsigned long  lasti       = 2;
unsigned long  found       = 0; // Number of primes we've found
unsigned long  rank        = 0; 

//A 32-bit unsigned int has a range from 0 to 4,294,967,295

void setup() {
  Serial.begin(115200);

  while (!Serial) { }

  start = millis();
}

void loop() {
  

  
  unsigned long prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) {

    rank ++;
    
    Serial.print("   ");
    Serial.print(i);
    Serial.print("   is   "); 
    Serial.print(rank); 
    Serial.println(" 'th   prime ");

    found++;
  }

  unsigned long running_seconds = (millis() - start) / 1000;

  if (max_seconds > 0 && (running_seconds >= max_seconds)) {
    Serial.print("-------     Found ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(max_seconds);
    Serial.println(" seconds    --------");
    //delay(60000);

  
    //i     = 2;
    found = 0;
    start = millis();
  }
if (i > lasti-1)
    {
    i++;
    }
else                        //if i counter has reset, rest the mcu for a while meanwhile do your analysis
  {
    Serial.print("-------     Total Runtime:   ");
    Serial.print(millis());
    Serial.print(" milliseconds(whole) i.e.   ");    
    Serial.print(millis()/1000);
    Serial.print(" seconds(whole) i.e.   ");
    Serial.print(millis()/60000); 
    Serial.print(" minutes(whole) i.e.   ");
    Serial.print(millis()/3600000);                   
    Serial.println(" hours(whole)    --------");       //please hook me up on a millis to HH:MM:SS:mSmS formatter :( {no libraries/RTCs please}
    delay(4294965295); //stop the mcu after Abouuut 49.7 days 
	delay(25034705);   //add 0.3 days and round the wait time to 50 days ¯\_(ツ)_/¯
    }
}

unsigned long is_prime(unsigned long num) {
  // Only have to check for divisible for the sqrt(number)
  unsigned long upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (unsigned long cnum = 2; cnum <= upper; cnum++) {
    unsigned long mod = num % cnum; // Remainder

    if (mod == 0) {
      return 0;
    } // If the remainer is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
lasti = i; // store largest prime, to stop further execution
}
