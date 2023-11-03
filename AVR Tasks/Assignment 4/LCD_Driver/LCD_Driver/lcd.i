# 1 "LCD_prog.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "LCD_prog.c"
# 11 "LCD_prog.c"
# 1 "Error_States.h" 1
# 15 "Error_States.h"
typedef enum
{
 ES_OK,
 ES_NOK,
 ES_NULL_POINTER,
 ES_OUT_OF_RANGE
}ES_t;
# 12 "LCD_prog.c" 2
# 1 "stdTypes.h" 1
# 14 "stdTypes.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef long double f80;
# 13 "LCD_prog.c" 2

# 1 "DIO_int.h" 1
# 46 "DIO_int.h"
ES_t DIO_enuINIT(void);


ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuSetPortVal(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuGetPortVal(u8 Copy_u8PortID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPortVal(u8 Copy_u8PortID);


ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuGetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID);
# 15 "LCD_prog.c" 2

# 1 "LCD_priv.h" 1
# 28 "LCD_priv.h"
static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command);
static ES_t LCD_enuLatch(u8 Copy_u8Command);
static void LCD_vidCheckPosition(void);
static void LCD_vidTrigger_LATCH(void);
# 17 "LCD_prog.c" 2
# 1 "LCD_config.h" 1
# 18 "LCD_prog.c" 2



static u8 LCD_u8PosCounter = 0;

ES_t LCD_enuInit(void)
{
 ES_t Local_enuErrorState = ES_NOK;


 Local_enuErrorState = DIO_enuSetPinDirection(0, 0, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(0, 1, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(0, 2, 1);


 Local_enuErrorState = DIO_enuSetPinDirection(1, 7, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 6, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 5, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 4, 1);

 _delay_ms(35);


 Local_enuErrorState = DIO_enuSetPinDirection(1, 3, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 2, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 1, 1);
 Local_enuErrorState = DIO_enuSetPinDirection(1, 0, 1);

 Local_enuErrorState = LCD_inlenuSendCommand(0x38);
 _delay_ms(1);
# 59 "LCD_prog.c"
 Local_enuErrorState = LCD_inlenuSendCommand(0x0F);
 _delay_ms(1);


 Local_enuErrorState = LCD_inlenuSendCommand(0x01);
 _delay_ms(2);


 Local_enuErrorState = LCD_inlenuSendCommand(0x06);
 _delay_ms(1);

 return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
 ES_t Local_enuErrorState = ES_NOK;


 Local_enuErrorState = DIO_enuSetPinVal(0, 0, 1);


 Local_enuErrorState = LCD_enuLatch(Copy_u8Data);

 return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
 ES_t Local_enuErrorState = ES_NOK;


 Local_enuErrorState = DIO_enuSetPinVal(0, 0, 0);


 Local_enuErrorState = LCD_enuLatch(Copy_u8Command);

 return Local_enuErrorState;
}

static ES_t LCD_enuLatch(u8 Copy_u8Data)
{
 ES_t Local_enuErrorState = ES_NOK;
 u8 Local_u8RSValue = 0;


 Local_enuErrorState = DIO_enuSetPinVal(0, 1, 0);


 Local_enuErrorState = DIO_enuSetPinVal(0, 2, 0);


 DIO_enuGetPinVal(0, 0, &Local_u8RSValue);
 if(Local_u8RSValue == 1)
 {
  LCD_vidCheckPosition();
 }



 Local_enuErrorState = DIO_enuSetPinVal(1, 7, ((Copy_u8Data >> 7) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 6, ((Copy_u8Data >> 6) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 5, ((Copy_u8Data >> 5) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 4, ((Copy_u8Data >> 4) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 3, ((Copy_u8Data >> 3) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 2, ((Copy_u8Data >> 2) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 1, ((Copy_u8Data >> 1) & 1));
 Local_enuErrorState = DIO_enuSetPinVal(1, 0, ((Copy_u8Data >> 0) & 1));
# 151 "LCD_prog.c"
 LCD_vidTrigger_LATCH();

 return Local_enuErrorState;
}

static void LCD_vidTrigger_LATCH(void)
{

 DIO_enuSetPinVal(0, 2, 1);
 _delay_ms(10);
 DIO_enuSetPinVal(0, 2, 0);
}

static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command)
{
 ES_t Local_enuErrorState = ES_NOK;


 Local_enuErrorState = DIO_enuSetPinVal(0, 0, 0);


 Local_enuErrorState = LCD_enuLatch(Copy_u8Command);

 return Local_enuErrorState;
}

ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position)
{
 ES_t Local_enuErrorState = ES_NOK;

 if(Copy_u8Position >= 0 && Copy_u8Position < 16)
 {
  if(Copy_u8Line == 1)
  {
   Local_enuErrorState = LCD_inlenuSendCommand(0x80 + Copy_u8Position);
  }
  else if(Copy_u8Line == 2)
  {
   Local_enuErrorState = LCD_inlenuSendCommand(0xC0 + Copy_u8Position);
  }
 }

 return Local_enuErrorState;
}

static void LCD_vidCheckPosition(void)
{
 if(LCD_u8PosCounter == 16)
 {
  LCD_enuGoToPosition(2, 0);
  LCD_u8PosCounter++;
 }
 else if(LCD_u8PosCounter == 32)
 {
  LCD_inlenuSendCommand(0x01);
  LCD_enuGoToPosition(1, 0);
  LCD_u8PosCounter = 0;
 }
 else
 {
  LCD_u8PosCounter++;
 }
}

void LCD_vidClearScreen(void)
{
 LCD_inlenuSendCommand(0x01);
 LCD_u8PosCounter = 0;
}

ES_t LCD_enuWriteString(u8 *Copy_pu8Str)
{
 ES_t Local_enuErrorState = ES_NOK;

 if(Copy_pu8Str != (void *)0)
 {
  while(*Copy_pu8Str != '\0')
  {
   Local_enuErrorState = LCD_enuDisplayChar(*Copy_pu8Str);
   Copy_pu8Str++;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }

 return Local_enuErrorState;
}
