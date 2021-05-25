#include "nbdelay.h"

Nonblockdelay::Nonblockdelay()
{
	delayFlag.time = 1000;
  	delayFlag.premillis=0; 
  	_indelay = false;
}

boolean Nonblockdelay::done()
{
  	if(!this-> delayFlag.started) 
    	return false;

  	if( (millis() - this-> delayFlag.premillis) > this-> delayFlag.time)
	{
    		this->stop();
    		return true;
  	}
  	return false;
}

void Nonblockdelay:: set(unsigned long t)
{
    	this->delayFlag.time = t;
}

void Nonblockdelay::_nbTimer()
{
  
  	this->reset();
 	this->delayFlag.started = true;
  	this-> _indelay = true;
}

void Nonblockdelay::reset()
{
  	this->stop();
  	this->delayFlag.premillis = millis();
}

void Nonblockdelay::stop()
{
 	this->delayFlag.started = false;
  	this-> _indelay = false;

}

boolean Nonblockdelay::indelay()
{
  	return (this->delayFlag.started && !this->done()) ? true : false;
}

void Nonblockdelay::nbdelay(unsigned long time, method function)
{
  	this->delayFlag.time = time;
  	delayFlag.now = millis();
  	if( (this->delayFlag.now - this-> delayFlag.premillis) > this-> delayFlag.time)
  	{
    		delayFlag.premillis= delayFlag.now;
    		function();
  	}
}
