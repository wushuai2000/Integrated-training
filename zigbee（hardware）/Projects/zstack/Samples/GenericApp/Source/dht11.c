#include "dht11.h"
#include "OnBoard.h"
#define DATA  P0_4

unsigned char temperature=0,humidity=0;
void DATA_IO_input_Cfg(void)//设置为上拉输入模式
{
    P0SEL &= 0xEF;   // 1110 1111 把P04设置为普通IO模式
    P0DIR &= 0xEF;   // 1110 1111 把P04设置为输入模式
    P0INP &= 0xEF;   // 1110 1111 把P04设置为上下拉模式
    P2INP &= 0xDF;   // 1101 1111 把P0组设置为上拉模式
}

void DATA_IO_output_Cfg(void)//设置为输出模式
{
    P0SEL &= 0xEF;   // 1110 1111 把P04设置为普通IO模式
    P0DIR |= 0x10;   // 0001 0000 把P04设置为输出模式
//    P0INP |= 0x10;   // 0001 0000 把P04设置为三态模式
}

unsigned char Read_Byte(void)
{
  unsigned char tmp=0,i;
  for(i=0;i<8;i++)
  {
    while(!(DATA ==0));//每个bit都是从50us的低电平开始
    while(!(DATA ==1));
    MicroWait(30);//延时30us
    if(DATA == 1)
    {
      tmp |= 1<<(7-i);//把该bit设置为1
    }
  }
  return tmp;
}

/*
@Start_DHT11 : 采集一次温湿度数据
@retval : 如果成功，把温湿度的值保存到全局变量，并返回1
          如果失败，返回0
*/
int Start_DHT11(void)//开始采集数据
{
  unsigned char buf[5];
  DATA_IO_output_Cfg();//设置为输出模式
  DATA = 0;//发送开始信号
  MicroWait(20000);//延时至少18ms
  DATA = 1;//拉高20~40us
  MicroWait(40);
  
  DATA_IO_input_Cfg();//设置为输入模式
  while(!(DATA ==0));//等DHT11回响应信号
  
  while(!(DATA ==1));//等DHT11把总线拉高，准备接收数据
  buf[0] = Read_Byte();
  buf[1] = Read_Byte();
  buf[2] = Read_Byte();
  buf[3] = Read_Byte();
  buf[4] = Read_Byte();

  
  if((buf[0]+buf[1]+buf[2]+buf[3])%256 == buf[4])
  {
    humidity = buf[0];
    temperature = buf[2];
    return 1;
  }
  return 0;
}


