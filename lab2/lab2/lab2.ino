#include <CustomStepper.h>            // Подключаем библиотеку управления шаговым двигателем 28BYJ-48-5V
CustomStepper eng(8, 9, 10, 11);  // Указываем пины

void setup()
{
  Serial.begin(9600);
  eng.setRPM(12);                 // Устанавливаем кол-во оборотов в минуту
  eng.setSPR(4075.7728395);       // Устанавливаем кол-во шагов на полный оборот. Максимальное значение 4075.7728395
}

// cw - clock 
// ccw - против
// stop - остановить
bool stoP = false;
void loop()
{
//  if(!stoP)
//  {
//    Deg(CW, 180);
//    stoP = !stoP;
//  }
  Just_go(CW, 1);
  eng.run();
}

template <typename val, typename dir>
void Just_go(dir direction, val rotate)
{
  if (eng.isDone()){
    eng.setDirection(direction);
    eng.rotate(rotate);
  }
}

template <typename dir, typename val>
void Deg(dir direction, val degrees)
{
  if(eng.isDone())
  {
    eng.setDirection(direction);
    eng.rotateDegrees(degrees);
  }
}
//
//template <typename dir>
//void WhileNoStop(dir direction)
//{
//  if(eng.isDone())
//  {
//    while(!(Serial.available()>0))
//    {
//      if(eng.isDone())
//      {
//        eng.setDirection(direction);
//        eng.rotate();
//      }
//    }
//  }
//}
