#include <Arduino.h>  

typedef void (*method)(void);

class Nonblockdelay
{
    public:
        Nonblockdelay();
        boolean done();
        boolean indelay();	
	void stop();	
	void reset();
        void set(unsigned long t);           
	void _nbTimer();
        void nbdelay(unsigned long , method);
    private:
        struct Nbd
        {
	  unsigned long time;
  	  unsigned long premillis;
          unsigned long now; 
	  boolean done;
          boolean started;
	};
        Nbd delayFlag;
	boolean _indelay;
        method  function;
};
