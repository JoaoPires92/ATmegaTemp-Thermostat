/*
 * Software Desenvolvido por Joao Pires
 * Data da Ultima Alteração: 18 ABR 2019
 */
 
  /* ************************+*** Guia de Ecras ********************************************
   * 0= Ecra Info
   * 1= Ecra Principal 
   * 2= Ecra Temperatura Zoom
   * 3= Gráfico Temperatura
   * 4= Controlo Automatico --> Temperatura máxima e Minima (Ecras Secondários: UpdateTempMax & UpdateTempMin)
   * 5= Ecra em modo Manual Temperatura --> Controla Output Temperatura (RL1) 
   * 6= Ecra para configurações --> Calibração da Temperatura (Ecras Secondários: Update Temp Direct & Update Temp Calib)
   * 7= Ecra para configurações --> Intervalo de leitura de temperatura e Humidade
   * 8= Ecra para configurações --> Acerto da data : Dia da semana & dia do mês
   * 9= Ecra para configurações --> Acerto da data : Mês & Ano
   * 10= Ecra para configurações --> Acerto do Tempo : Hora & Minuto
   * 11= Controlo do Relé de temperatura RL1 (modo 2: contacto NA Modo 1: Inverte contacto para NF)
   * 12= Ecra Humidade Zoom
   * 13= Gráfico Humidade
   * 14= Controlo Automatico --> Humidade máxima e Minima (Ecras Secondários: UpdateHumMax & UpdateHumMin)
   * 15= Ecra em modo Manual Humidade --> Controla Output Humidade (RL2) 
   * 16= Ecra para configurações --> Calibração da Humidade (Ecras Secondários: UpdateHumDirect & UpdateHumCalib)
   * 17= Ecra para Estado Atual dos Outputs
   * 18= Controlo do Relé de Humidade RL2 (modo 2: contacto NA Modo 1: Inverte contacto para NF)
   * 19= Ecra Gráfico Humidade e Temperatura
   * 20= Ecra Tabela de Registos de Temperatura e Humidade
   * 21= Menu Selecionar: Grafico , Registo Dados , Temperatura/Humidade Zoom
   * 22= Ecra Para Configuracoes --> Seleionar Intervalo para Registo de Dados
   * 23= Menu Selecionar: Configuracoes 1
   * 24= Menu Selecionar: Configuracoes 1
   * 25= Ecra em modo Manual Saida RL3 --> Controla Output (RL3)
   * 26= Ecra em modo Manual Saida RL4 --> Controla Output (RL4)
   * 27= Ecra para escolher RL1&RL2 ou RL3&RL4 no Ecra Principal
   * 28= Controlo do Relé RL3 (modo 2: contacto NA Modo 1: Inverte contacto para NF)
   * 29= Controlo do Relé RL4 (modo 2: contacto NA Modo 1: Inverte contacto para NF)
   * 30= Saida RL3 Programar Dias da Semana 
   * 31= Saida RL3 Programar Horario
   * 32= Saida RL4 Programar Dias da Semana 
   * 33= Saida RL4 Programar Horario
   * 34= Config Menu 2 - Botão 3 Ecra & Outros - Screen Saver Timeout
   * 
   * 
   * 100= Screen Saver
   * 101= Ecra Inicial Se Cartão SD estiver Inserido
   */

   /*Screen Layout Botoes de fundo Guia:
    * 
    * ScreenLayout() = Back - Down - Up - Next
    * ScreenLayout1() = Back - Next
    * ScreenLayout2() = Next
    * ScreenLayout3() = Back
    * ScreenLayout4() = Back - Down - Up
    */

  /* EEPROM Memory --> Size 4096 bytes (Escreve até posição 4096)
   *  
   * 0:Estado da Máquina 
   * 1:Temp Maxima 
   * 2:Temp Minima 
   * 3:Temp Intervalo de Leitura 
   * 4:Temperatura modo Controlo relé NO / NC - Normal/Invertido
   * 5:Temperatura Directa 
   * 6:Temperatura Calibrada 
   * 7:Gráfico Monstrar Linhas para Temp Max e Temp Minima
   * 8:Humidade Maxima 
   * 9:Humidade Minima 
   * 10:Humidade Directa
   * 11:Humidade Calibrada 
   * 12:Humidade modo Controlo relé NO / NC - Normal/Invertido 
   * 13:Gráfico Monstrar Linhas para Hum Max e Hum Minima 
   * 14:Last Day On 
   * 15:Intervalo Registo Eventos (min) 
   * 16:RL3 modo Controlo relé NO / NC - Normal/Invertido 
   * 17:RL4 modo Controlo relé NO / NC - Normal/Invertido 
   * 18:Ecra Principal mostrat Outputs RL1&RL2 ou RL3&RL4
   * 19:RL3 Config Monday
   * 20:RL3 Config Tuesday
   * 21:RL3 Config Wednesday
   * 22:RL3 Config Thursday
   * 23:RL3 Config Friday
   * 24:RL3 Config Saturday
   * 25:RL3 Config Sunday
   * 26:RL3 Config Off
   * 27:RL4 Config Monday
   * 28:RL4 Config Tuesday
   * 29:RL4 Config Wednesday
   * 30:RL4 Config Thursday
   * 31:RL4 Config Friday
   * 32:RL4 Config Saturday
   * 33:RL4 Config Sunday
   * 34:RL4 Config Off
   * 35:RL3 Config Hour ON
   * 36:RL3 Config Minutes ON 
   * 37:RL3 Config Hour Off
   * 38:RL3 Config Minutes Off
   * 39:RL4 Config Hour ON
   * 40:RL4 Config Minutes ON 
   * 41:RL4 Config Hour Off
   * 42:RL4 Config Minutes Off
   * 43:Screen Saver Timeout
   * 44:Temperatura Directa Casa Decimal
   * 45:Temperatura Calibrada Casa Decimal
   * 46: Humidade Directa Casa Decimal
   * 47: Humidade Calibrada Casa Decimal
   * 
   * 50 - 98 --> Reserva 
   * 
   * 99 - 195--> Grafico Temperatura -> (99 == eeprom pos 100 para inicio do gráfico) -> 100 - 195 Valores de temperatura escritos para gráfico
   * 
   * 199 - 295 --> Grafico Humidade -> (199 == eeprom pos 200 para inicio do gráfico) -> 200 - 295 Valores de Humidade escritos para gráfico
   * 
   * 300 - 395 --> Tabela Registo de Dados Temperatura a cada 15 min sem casa decimal
   * 400 - 495 --> Tabela Registo de Dados Humidade a cada 15 min sem casa decimal
   * 
   *500 - 595 --> Tabela Registo de Dados Temperatura a cada 15 min apenas casa decimal
   *600 - 695 --> Tabela Registo de Dados Humidade a cada 15 min apenas casa decimal
   * 
   * 
   * 4096 --> Limite máximo de momória
   */

   /*IO's Guia
    * SNS : 31
    * RL1 : 29
    * RL2 : 27 
    * RL3 : 25
    * RL4 : 23
    */

    /*Comandos Porta Serie: VB.net --> Arduino
     * 
     * Comandos do VB->Arduino
     * @RSED & File Date & @ - Read Serial Eventes Data - Pedido de leitura do ficheiro guardado no cartão SD
     * @RSSN@ - Read Serial Serial Number - Ler o Numero de Serie e mês/ano de fabrico
     * @RSFD@ - SD File Delete - Command to Delete File
     * 
     * Comandos do Arduino -> VB
     * Envio de dados apartir do ficheiro no Cartão SD--> Acess SD Card - Open File Name requested - Send--> @WSED|Dia|Mes|Ano|Hora|Minuto|Temp|Hum|@
     * Enviar Informação do Controlador --> @WSSN|SN|Mes|Ano|@
     * Respostas de Erro 
     * @WSCNR@ - Write Serial Command not Received
     * @WSOFE@ - Write Serial Open File Error
     * @WSNFF@ - Write Serial No File Found
     * @WSNCF@ - Write Serial No Card Found
     * 
     */


//*********************Librarias************************* 
#include <DallasTemperature.h>
#include <OneWire.h>
#include <EEPROM.h>
#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>  
#include <TouchScreen.h>
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <SD.h>

String StrDeviceInfo = "|2019040001|4|2019"; // Enviar Informação do Aparelho para VB --> |Device SN|Device Month|Device Year 

//********************************** Ecra Info: Definir numero de Serie do aparelho e data de fabricação ************************* 

String DeviceModel = "ATmega Temp-04"; //Tipo de aparelho --> nome nao deve ser mais longo que 18 caracteres
String DeviceSN = "2019040001"; // Numero de Serie 10 caracteres 
int DeviceMonth = 4; // Mes de Fabrico
int DeviceYear = 2019; // Ano de Fabrico
String DeviceDeveloper = "Joao Pires"; // Desenvolvido Por
char devicemonth[12][12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

//************************************** Variaveis Globais *******************************************

float Temperature; // usado para converter em 1 casa decimal
float Temperature_Aux =1; // usado para escrever temperatura no ecra apenas quando valor altera
float Humidity; // usado para converter em 1 casa decimal
float Humidity_Aux =1; // usado para escrever temperatura no ecra apenas quando valor altera
int TemperatureDec; // Usado para obter apenas casa decimal da temperatura
int HumidityDec;// Usado para obter apenas casa decimal da temperatura
int Val_TempCalib;
int Val_TempDirect;
int Val_TempCalibAux;
int Val_TempDirectAux;
int TemperatureMax;
int TemperatureMin;
int HumidityMax;
int HumidityMin;
int Val_HumCalib;
int Val_HumDirect;
int Val_HumCalibAux;
int Val_HumDirectAux;
int TemperatureControl; // Inverter funcionamento do relé para controlo da temperatura 1= Invertido | 2= Normal
int HumidityControl; // Inverter funcionamento do relé para controlo da Humidade 1= Invertido | 2= Normal
int RL3OutputControl; // Inverter funcionamento do relé para controlo do Output RL3:1= Invertido | 2= Normal
int RL4OutputControl; // Inverter funcionamento do relé para controlo do Output RL3:1= Invertido | 2= Normal

int CurrentScreen;

boolean ButtonNext = false;
boolean ButtonBack = false;
boolean ButtonUp = false;
boolean ButtonDown = false;

boolean TMaxPressed = false;
boolean TMinPressed = false;
boolean HMaxPressed = false;
boolean HMinPressed = false;
boolean TDirectPressed = false;
boolean TCalibPressed = false;
boolean HDirectPressed = false;
boolean HCalibPressed = false;

int MachineStatus; // 0 : Modo Manual  1 : Modo Automático 

unsigned long PreviousTempHumReadInterval = 0;  // will store last time Temperature was updated
int TempHumReadInterval;  // interval to update temperature (milliseconds)

boolean Flg_TempHumAlarm = false;
boolean Flg_TempHumAlarmLastStatus = false;

// Outputs
int DO_Temperature = 29; // RL1
int DO_Humidity = 27; // RL2
int DO_RL3 = 25; // RL3
int DO_RL4 = 23; // RL4

// RTC Variaveis
char daysOfTheWeek[7][12] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"}; // Defines RTC DaysOfWeek
String DaysOfTheWeek;
int Aux_DayOfTheWeek;
int DayOfWeek;
int Minute_old;
int Day;
int Month;
int Year;
int Hour;
int Minute;
int Second;
int Old_Second=70;
int Old_Minute=70;
int LastDayOn;
boolean Flg_RTCAlarm=false;
boolean Flg_RTCAlarmLastStatus=false;

boolean DayOfWeekPressed = false;
boolean DayPressed=false;
boolean MonthPressed=false;
boolean YearPressed=false;
boolean HourPressed=false;
boolean MinutePressed=false;

int GraphPointer;
int Graph_TMax_TMin;

int GraphPointer1;
int Graph_HMax_HMin;

int RL1OutputStatus;
int RL1_Old_OutputStatus;
int RL2OutputStatus;
int RL2_Old_OutputStatus;
int RL3OutputStatus;
int RL3_Old_OutputStatus;
int RL4OutputStatus;
int RL4_Old_OutputStatus;
int DisplayOutputsScreen1; // 0: Mostra Output RL1 e RL2 | 1: Mostra Output RL3 e RL4

boolean TempHomePressed=false;
boolean HumHomePressed=false;

int AuxHourScreen20;

int EventsRegInterval;

boolean SDCardOk=false;
File myFile; // Ficheiro Texto para SD card
char FileName[] = "00000000.txt";
char VBRequestFileName[] = "00000000.txt";

String mySt="";
char myChar[]="00000000000000000000";
int myCharPoinrer=0;

int RL3ConfigMon; // 0= Off 1= On. 
int RL3ConfigTue;
int RL3ConfigWed;
int RL3ConfigThu;
int RL3ConfigFri;
int RL3ConfigSat;
int RL3ConfigSun;
int RL3ConfigOff;
int RL3ConfigHourOn;
int RL3ConfigMinuteOn;
int RL3ConfigHourOff;
int RL3ConfigMinuteOff;
boolean RL3HourOnPressed = false;
boolean RL3MinuteOnPressed = false;
boolean RL3HourOffPressed = false;
boolean RL3MinuteOffPressed = false; 

int RL4ConfigMon;  // 0= Off 1= On. 
int RL4ConfigTue;
int RL4ConfigWed;
int RL4ConfigThu;
int RL4ConfigFri;
int RL4ConfigSat;
int RL4ConfigSun;
int RL4ConfigOff;
int RL4ConfigHourOn;
int RL4ConfigMinuteOn;
int RL4ConfigHourOff;
int RL4ConfigMinuteOff;
boolean RL4HourOnPressed = false;
boolean RL4MinuteOnPressed = false;
boolean RL4HourOffPressed = false;
boolean RL4MinuteOffPressed = false; 

int ScreenSaverTimeout; // 0= desligado 
int ScreenSaverTimeoutCnt=0;
int ScreenSaverDelay=5; // Delay de 5 segundos para atualizar proteção de Ecra

//******Parametros para o LCD Elegoo ********
#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

// **********Parametros para Cartão SD ***********
#define SD_SCK 13
#define SD_MISO 12
#define SD_MOSI 11
#define SD_CS 10 

// Pressão do toque para o LCD
//#define PENRADIUS 3
#define MINPRESSURE 10
#define MAXPRESSURE 1000

// Valores de Calibração para o LCD Elegoo
#define TS_MINX 128
#define TS_MINY 77
#define TS_MAXX 903
#define TS_MAXY 892

// Parametros para touch Touch Screen Elegoo
#define YP A3 
#define XM A2  
#define YM 9   
#define XP 8   


// Definição de Cores para o LCD

#define BLACK 0x0000 
#define NAVY 0x000F 
#define DARKGREEN 0x03E0 
#define DARKCYAN 0x03EF 
#define MAROON 0x7800 
#define PURPLE 0x780F 
#define OLIVE 0x7BE0 
#define GREY 0xC618 
#define DARKGREY 0x7BEF 
#define BLUE 0x001F 
#define GREEN 0x07E0 
#define CYAN 0x07FF 
#define RED 0xF800 
#define MAGENTA 0xF81F 
#define YELLOW 0xFFE0 
#define WHITE 0xFFFF 
#define ORANGE 0xFD20 
#define GREENYELLOW 0xAFE5 
#define PINK 0xF81F


//*************Declaração LCD & Touch Screen************

  Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
  TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); // Chamada para Touch
  
//*************Declaração Sensor Temperatura & Humidade************
  #define ONE_WIRE_BUS 31 // Declaração do sensor temperatura pino 31
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature sensors(&oneWire);
  
//************* Declaração RTC DS1307****************
  RTC_DS1307 rtc;

//:::::::::::::::::::::::::::::: Inicio do Programa Setup (Executa apenas 1x) ::::::::::::::::::::::::::::::::::::::::::
  void setup() {

// Declarar pino 31 para input Sensor Temperatura
  pinMode(31,INPUT);

// Declarar Outputs para relés de interface
  pinMode(DO_Temperature,OUTPUT);
  pinMode(DO_Humidity,OUTPUT);
  pinMode(DO_RL3,OUTPUT);
  pinMode(DO_RL4,OUTPUT);
  
 //********************************  Iniciar LCD  ***************************************
  tft.reset();
  uint16_t identifier = tft.readID();
  identifier=0x9341;
  tft.begin(identifier);
  tft.setRotation(3);
  tft.setTextSize(2);
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
    
//*********************************** Iniciar Porta Série********************************
  Serial.begin(115200);

// **********************************Iniciar RTC***************************
  rtc.begin();
      
// ***********Acertar a hora e data do RTC para Primeira Programação ****************

   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

// ************************************* Iniciar variaveis ************************************ 
 //Enviar na primeira programação
 /*
  EEPROM.write(0,1); 
  EEPROM.write(1,55);
  EEPROM.write(2,35);
  EEPROM.write(3,3);
  EEPROM.write(4,2);
  EEPROM.write(5,50);
  EEPROM.write(6,50);
  EEPROM.write(7,0);
  EEPROM.write(8,80);
  EEPROM.write(9,40);
  EEPROM.write(10,50);
  EEPROM.write(11,50);
  EEPROM.write(12,2);
  EEPROM.write(13,0);
  EEPROM.write(14,0);
  EEPROM.write(15,0);
  EEPROM.write(16,2);
  EEPROM.write(17,2);
  EEPROM.write(18,0);
  EEPROM.write(19,0);
  EEPROM.write(20,0);
  EEPROM.write(21,0);
  EEPROM.write(22,0);
  EEPROM.write(23,0);
  EEPROM.write(24,0);
  EEPROM.write(25,0);
  EEPROM.write(26,1);
  EEPROM.write(27,0);
  EEPROM.write(28,0);
  EEPROM.write(29,0);
  EEPROM.write(30,0);
  EEPROM.write(31,0);
  EEPROM.write(32,0);
  EEPROM.write(33,0);
  EEPROM.write(34,1);
  EEPROM.write(35,0); 
  EEPROM.write(36,0); 
  EEPROM.write(37,0); 
  EEPROM.write(38,0);
  EEPROM.write(39,0); 
  EEPROM.write(40,0); 
  EEPROM.write(41,0); 
  EEPROM.write(42,0);
  EEPROM.write(43,0);
  EEPROM.write(44,0);
  EEPROM.write(45,0);
  EEPROM.write(46,0);
  EEPROM.write(47,0);   
 */

  MachineStatus = EEPROM.read(0);
  TemperatureMax = EEPROM.read(1);
  TemperatureMin = EEPROM.read(2);
  TempHumReadInterval = EEPROM.read(3);
  TemperatureControl= EEPROM.read(4);
  Val_TempDirect = EEPROM.read(5);
  Val_TempCalib = EEPROM.read(6);
  Graph_TMax_TMin = EEPROM.read(7);
  HumidityMax = EEPROM.read(8);
  HumidityMin = EEPROM.read(9);
  Val_HumDirect = EEPROM.read(10);
  Val_HumCalib = EEPROM.read(11);
  HumidityControl= EEPROM.read(12);
  Graph_HMax_HMin = EEPROM.read(13);
  LastDayOn = EEPROM.read(14);
  EventsRegInterval = EEPROM.read(15); 
  RL3OutputControl = EEPROM.read(16);
  RL4OutputControl = EEPROM.read(17); 
  DisplayOutputsScreen1=EEPROM.read(18); 
  RL3ConfigMon=EEPROM.read(19); 
  RL3ConfigTue=EEPROM.read(20);
  RL3ConfigWed=EEPROM.read(21);
  RL3ConfigThu=EEPROM.read(22);
  RL3ConfigFri=EEPROM.read(23);
  RL3ConfigSat=EEPROM.read(24);
  RL3ConfigSun=EEPROM.read(25);
  RL3ConfigOff=EEPROM.read(26);  
  RL4ConfigMon=EEPROM.read(27);
  RL4ConfigTue=EEPROM.read(28);
  RL4ConfigWed=EEPROM.read(29);
  RL4ConfigThu=EEPROM.read(30);
  RL4ConfigFri=EEPROM.read(31);
  RL4ConfigSat=EEPROM.read(32);
  RL4ConfigSun=EEPROM.read(33);
  RL4ConfigOff=EEPROM.read(34); 
  RL3ConfigHourOn=EEPROM.read(35);
  RL3ConfigMinuteOn=EEPROM.read(36);
  RL3ConfigHourOff=EEPROM.read(37);
  RL3ConfigMinuteOff=EEPROM.read(38);
  RL4ConfigHourOn=EEPROM.read(39);
  RL4ConfigMinuteOn=EEPROM.read(40);
  RL4ConfigHourOff=EEPROM.read(41);
  RL4ConfigMinuteOff=EEPROM.read(42);  
  ScreenSaverTimeout=EEPROM.read(43);
  Val_TempDirectAux=EEPROM.read(44);
  Val_TempCalibAux=EEPROM.read(45);
  Val_HumDirectAux=EEPROM.read(46);
  Val_HumCalibAux=EEPROM.read(47);

 // *********** Chamar Rotinas RTC e Temperatura/Humidade para obter valor antes de iniciar ecra 1 ***********
  ReadRTC();
  PreviousTempHumReadInterval = 0;
  TempHumReadInterval = TempHumReadInterval*1000;
  GetTempHum();
  Humidity = 0;

 // ************************ Saber quando foi o Ultimo dia de uso do Controlador para fazer reset aos Gráficos e Tabela de Registos **********************
  if (LastDayOn != Day){
      GraphTempValuesReset();
      GraphHumValuesReset();
      TempEventDataReset();
      HumEventDataReset();
      LastDayOn=Day;
      EEPROM.write(14,LastDayOn);   
  }

  // ******************************* Iniciar Outputs RL1 & RL2 ****************************** 
  if(MachineStatus == 1){
    if(TemperatureControl==1){digitalWrite(DO_Temperature,LOW);}
    if(TemperatureControl==2){digitalWrite(DO_Temperature,HIGH);}
    if(HumidityControl==1){digitalWrite(DO_Humidity,LOW);}
    if(HumidityControl==2){digitalWrite(DO_Humidity,HIGH);}     
    AutoTempControl(); 
  }
  else{
    if(TemperatureControl==1){digitalWrite(DO_Temperature,LOW);}
    if(TemperatureControl==2){digitalWrite(DO_Temperature,HIGH);}
    if(HumidityControl==1){digitalWrite(DO_Humidity,LOW);}
    if(HumidityControl==2){digitalWrite(DO_Humidity,HIGH);}     
  }

  // ************************************** Iniciar Outputs RL3 & RL4 ********************************** 
  if(MachineStatus == 1){
    if(RL3OutputControl==1){digitalWrite(DO_RL3,LOW);}
    if(RL3OutputControl==2){digitalWrite(DO_RL3,HIGH);}
    if(RL4OutputControl==1){digitalWrite(DO_RL4,LOW);}
    if(RL4OutputControl==2){digitalWrite(DO_RL4,HIGH);}
    AutoRL3Control(); 
    AutoRL4Control();
  }
  else{
    if(RL3OutputControl==1){digitalWrite(DO_RL3,LOW);}
    if(RL3OutputControl==2){digitalWrite(DO_RL3,HIGH);}
    if(RL4OutputControl==1){digitalWrite(DO_RL4,LOW);}
    if(RL4OutputControl==2){digitalWrite(DO_RL4,HIGH);}
  }
  // ******************************* Obter Estado dos Outputs antes de iniciar Ecra 1 ***************************** 
// Saber o estado do Output RL1  
  RL1OutputStatus=0;
  RL1OutputStatus = digitalRead(DO_Temperature);
  RL1_Old_OutputStatus=2;

// Saber o estado do Output RL2  
  RL2OutputStatus=0;
  RL2OutputStatus = digitalRead(DO_Humidity);
  RL2_Old_OutputStatus=2;

// Saber o estado do Output RL3  
  RL3OutputStatus=0;
  RL3OutputStatus = digitalRead(DO_RL3);
  RL3_Old_OutputStatus=2;

// Saber o estado do Output RL4  
  RL4OutputStatus=0;
  RL4OutputStatus = digitalRead(DO_RL4);
  RL4_Old_OutputStatus=2;

 //***************************** Verificar Inico do Cartão SD *****************************
  tft.println("A Pesquisar o cartao SD...");
  delay(500);
  if (!SD.begin(SD_CS, SD_MOSI, SD_MISO, SD_SCK )) {
    tft.println("Cartao SD nao Inserido!");
    SDCardOk=false;
     delay(1000);}
   else{     
    tft.println("Cartao SD Inserido Ok!");
    SDCardOk=true;
    delay(1000);}
    
//***************** Iniciar Ecra de Apresentação e Principal ****************
  CurrentScreen=101;
  Screen101();
  GetTempHum();
  if(MachineStatus == 1){AutoTempControl();}
  delay(5000);  
  CurrentScreen =1;
  Screen1();
}

  void loop() {
   
// Rotina Multitask para chamada da leitura de temperatura e humidade
  unsigned long CurrentTempHumReadInterval = millis();
  if (CurrentTempHumReadInterval - PreviousTempHumReadInterval >= TempHumReadInterval) {   
      PreviousTempHumReadInterval = CurrentTempHumReadInterval;
      GetTempHum();
    }
  
// Chamar rotina para identificar botão pressionado no ecra touch 
    AnyButtonPressed();
    
// Chamar rotina para obter coordenadas touch para botões. (Apenas para setup)
    //TouchButtonTeach();
    
// Chamar RTC para leitura  
    if(CurrentScreen!=8 && CurrentScreen!=9 && CurrentScreen!=10){ReadRTC();}
    
// Chamar Rotina para controlo de temperatura em Automatico
    if(MachineStatus==1){AutoTempControl();}

// Chamada para escrever registos no Cartao SD
    if(EventsRegInterval!=0 && Second==59 && SDCardOk==true  && Flg_TempHumAlarm==false && Flg_RTCAlarm==false){GetEventsRegInterval();}   
    
// Chamar Rotinas para Registo de Eventos de Temperature e Humidade para Graficos e Tabela
   if((Minute==0 || Minute==15 || Minute==30 || Minute==45) && Second==59 && Flg_TempHumAlarm==false && Flg_RTCAlarm==false){
      GraphSaveTemperature(); // Chamar Rotina para guardar valor da temperatura para gráfico
      SaveTempEventData(); // Chamada para escrever Registo para Ecra 20 (Tabela de Registos)
      if(CurrentScreen==20){
        TSPoint p = ts.getPoint();
         pinMode(XM, OUTPUT);
         pinMode(YP, OUTPUT);      
         CurrentScreen=20;
         Screen20();
      }
   }

   // Chamar Rotina para Receber Comandos Serial do Visual Basic 'Events Downloader App'
    if (Serial.available() > 0){VBDataRequest();}
    

    if (Second!=Old_Second){ //***************************** Rotina de Chamada de 1 Segundo ****************************************************
         
       if(MachineStatus==1 && RL3ConfigOff==0){AutoRL3Control();} // Chamar Rotina para controlo de Saida programada RL3
       if(MachineStatus==1 && RL3ConfigOff!=0){RL3OutputOff();}  // Desligar Saida RL3 se programa semanal estiver desligado

       if(MachineStatus==1 && RL4ConfigOff==0){AutoRL4Control();} // Chamar Rotina para controlo de Saida programada RL4
       if(MachineStatus==1 && RL4ConfigOff!=0){RL4OutputOff();}  // Desligar Saida RL4 se programa semanal estiver desligado
  
        // Estado da Output RL1
        RL1OutputStatus = digitalRead(DO_Temperature);
        if(RL1OutputStatus != RL1_Old_OutputStatus && (CurrentScreen==1 || CurrentScreen==17)){
           PrintOutputStatus(); 
           RL1_Old_OutputStatus = RL1OutputStatus;
         }
      
        // Estado da Output RL2
      /*  RL2OutputStatus = digitalRead(DO_Humidity);
        if(RL2OutputStatus != RL2_Old_OutputStatus && (CurrentScreen==1 || CurrentScreen==17)){
           PrintOutputStatus(); 
           RL2_Old_OutputStatus = RL2OutputStatus;
        }
        */
         // Estado da Output RL3
        RL3OutputStatus = digitalRead(DO_RL3);
        if(RL3OutputStatus != RL3_Old_OutputStatus && (CurrentScreen==1 || CurrentScreen==17)){
           PrintOutputStatus(); 
           RL3_Old_OutputStatus = RL3OutputStatus;
        }
        
        // Estado da Output RL4
        RL4OutputStatus = digitalRead(DO_RL4);
        if(RL4OutputStatus != RL4_Old_OutputStatus && (CurrentScreen==1 || CurrentScreen==17)){
           PrintOutputStatus(); 
           RL4_Old_OutputStatus = RL4OutputStatus;
        }
                
    // Ativar a Protecao de Ecra
    if(ScreenSaverTimeout>0){
              
        if(ScreenSaverTimeoutCnt<=ScreenSaverTimeout*60){
            ScreenSaverTimeoutCnt++;
        }
        else{
            ScreenSaverDelay++;
               if(ScreenSaverDelay>=5){
                   pinMode(XM, OUTPUT);
                   pinMode(YP, OUTPUT);
                   CurrentScreen=100;
                   Screen100();
                   ScreenSaverDelay=0;
               }    
        }
    }

      Old_Second=Second;    
    } 
        
  // *********** Reset de todas as memórias EEPROM quando novo dia começa ***********************
    if (Hour==0 && Minute==0 && LastDayOn != Day){
        GraphTempValuesReset();
        //GraphHumValuesReset();
        TempEventDataReset();
        //HumEventDataReset();
        LastDayOn=Day;
        EEPROM.write(14,LastDayOn);   
    }
}

 void GetTempHum(){

    float Aux_TempDirect;
    float Aux_TempCalib;

    Aux_TempDirect = (((Val_TempDirect*10)+Val_TempDirectAux)/10);
    Aux_TempCalib = (((Val_TempCalib*10)+Val_TempCalibAux)/10);
  
    sensors.requestTemperatures();
    Temperature = ((sensors.getTempCByIndex(0)* Aux_TempCalib) / Aux_TempDirect);
    if(Temperature>=125){Temperature=125;}
    
    if(Temperature==-127.0){
        Flg_TempHumAlarm=true;
        Flg_TempHumAlarmLastStatus=true;
        if(CurrentScreen==1){PrintMachineStatus();}
      }
      else{
        Flg_TempHumAlarm=false;
        if(Flg_TempHumAlarmLastStatus==true){
          PrintMachineStatus();
          Flg_TempHumAlarmLastStatus=false;
        }
      }
    
// Chamar ecra para escrever Temperatura
   if(Temperature != Temperature_Aux && (CurrentScreen==1 || CurrentScreen==2 || CurrentScreen==5)){        
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
            
      UpdateTemperature();    
      Temperature_Aux = Temperature;
   } 

// Chamar ecra para escrever Humidade
  /* if(Humidity != Humidity_Aux && (CurrentScreen==1 || CurrentScreen==12 || CurrentScreen==15)){        
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      
      UpdateHumidity();     
      Humidity_Aux = Humidity;
   }
   */ 
}

 void PrintTempHum(){

  if (CurrentScreen==1){
      //linhas para Cabeçalho 
      tft.drawLine(5,55,315,55,WHITE);
      tft.drawLine(5,56,315,56,WHITE); 
      //tft.drawLine(158,56,158,3,WHITE);
      //tft.drawLine(159,56,159,3,WHITE);
  
      tft.setCursor(222,8);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.print("o");
      tft.setCursor(236,17);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("C");
  
      //tft.setCursor(273,24);
      //tft.setTextColor(WHITE);
      //tft.setTextSize(2);
      //tft.print("%RH");
  
      UpdateTemperature();
      //UpdateHumidity();
  }
  
  else if (CurrentScreen==5){UpdateTemperature();} 
  else if (CurrentScreen==15){UpdateHumidity();}

  else if(CurrentScreen==2){

      tft.drawLine(5,45,315,45,WHITE);
      tft.drawLine(5,46,315,46,WHITE); 
      tft.setCursor(58,12);
      tft.setTextColor(GREENYELLOW);
      tft.setTextSize(3);
      tft.print("Temperatura"); 
  
      UpdateTemperature();
  
      tft.setCursor(261,83);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("o");  
      tft.setCursor(281,98);
      tft.setTextColor(WHITE);
      tft.setTextSize(5);
      tft.print("C");      
  }

  else if(CurrentScreen==12){

      tft.drawLine(5,45,315,45,WHITE);
      tft.drawLine(5,46,315,46,WHITE); 
      tft.setCursor(90,12);
      tft.setTextColor(GREENYELLOW);
      tft.setTextSize(3);
      tft.print("Humidade"); 
  
      UpdateHumidity();
  
      tft.setCursor(259,105);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("%RH");         
  } 
            
 }

 void UpdateTemperature(){

    if (CurrentScreen==1){
        tft.fillRect(65,5,155,50,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(6);
        tft.setCursor(74,9);
        if(Temperature<100 && Flg_TempHumAlarm==false){tft.println(Temperature,1);}
        else if(Temperature>=100 && Flg_TempHumAlarm==false){tft.println(Temperature,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}     
    }

    else if (CurrentScreen==5){
        tft.fillRect(8,125,109,44,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(4);
        tft.setCursor(16,135);
        if(Temperature<100 && Flg_TempHumAlarm==false){tft.println(Temperature,1);}
        else if(Temperature>=100 && Flg_TempHumAlarm==false){tft.println(Temperature,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}     
    }

    else if(CurrentScreen==2){
        tft.fillRect(8,75,250,100,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(10);
        tft.setCursor(16,90);
        if(Temperature<100 && Flg_TempHumAlarm==false){tft.println(Temperature,1);}
        else if(Temperature>=100 && Flg_TempHumAlarm==false){tft.println(Temperature,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}       
    }
 }

 void UpdateHumidity(){

    if (CurrentScreen==1){
        tft.fillRect(164,8,105,44,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(4);
        tft.setCursor(170,17);
        if(Humidity<100 && Flg_TempHumAlarm==false){tft.println(Humidity,1);}
        else if(Humidity>=100 && Flg_TempHumAlarm==false){tft.println(Humidity,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}     
    }

    else if (CurrentScreen==15){
        tft.fillRect(8,125,109,44,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(4);
        tft.setCursor(16,135);
        if(Humidity<100 && Flg_TempHumAlarm==false){tft.println(Humidity,1);}
        else if(Humidity>=100 && Flg_TempHumAlarm==false){tft.println(Humidity,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}    
    }

    else if(CurrentScreen==12){
        tft.fillRect(8,75,250,100,BLACK);
        tft.setTextColor(WHITE);
        tft.setTextSize(10);
        tft.setCursor(16,90);
        if(Humidity<100 && Flg_TempHumAlarm==false){tft.println(Humidity,1);}
        else if(Humidity>=100 && Flg_TempHumAlarm==false){tft.println(Humidity,0);}
        else if(Flg_TempHumAlarm==true){tft.println("##.#");}       
    }     
 }

  void PrintScreenLayout(){

    tft.fillScreen(BLACK);
// Draw Rectangle frame
    tft.drawRect(5,3,312,192,WHITE);
    tft.drawRect(4,4,312,190,WHITE);

// Button Back
    tft.fillRect(5,198,74,40,DARKGREY);
    tft.drawRect(5,198,74,40,WHITE);
    tft.drawRect(4,199,74,38,WHITE);    
    tft.setCursor(22,208);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print("<<");
    
// Button Down
    tft.fillRect(84,198,74,40,DARKGREY);
    tft.drawRect(84,198,74,40,WHITE);
    tft.drawRect(83,199,74,38,WHITE);

    if(CurrentScreen==11 || CurrentScreen==18 || CurrentScreen==28 || CurrentScreen==29){
      tft.setCursor(86,210);
      tft.setTextColor(BLACK);
      tft.setTextSize(2);
      tft.print("Inver.");       
    }
    else if(CurrentScreen==5 || CurrentScreen==15 || CurrentScreen==25 || CurrentScreen==26){
      tft.setCursor(95,208);   
      tft.setTextSize(3);
       tft.print("OFF");      
    }
    else{
      tft.setCursor(113,208);
      tft.setTextColor(BLACK);
      tft.setTextSize(3);
      tft.print("-");        
    }

// Button UP
    tft.fillRect(163,198,74,40,DARKGREY);
    tft.drawRect(163,198,74,40,WHITE);
    tft.drawRect(162,199,74,38,WHITE);

    if(CurrentScreen==11 || CurrentScreen==18 || CurrentScreen==28 || CurrentScreen==29){
      tft.setCursor(173,210);
      tft.setTextColor(BLACK);
      tft.setTextSize(2);
      tft.print("Norm.");       
    }
    else if(CurrentScreen==5 || CurrentScreen==15 || CurrentScreen==25 || CurrentScreen==26){
      tft.setCursor(183,208);
      tft.setTextSize(3);
      tft.print("ON");
    }
    else{
      tft.setCursor(192,208);
      tft.setTextColor(BLACK);
      tft.setTextSize(3);
      tft.print("+");   
    }

// Button NEXT
    tft.fillRect(242,198,75,40,DARKGREY);
    tft.drawRect(242,198,75,40,WHITE);
    tft.drawRect(241,199,75,38,WHITE);
  if(CurrentScreen==20){
    tft.setCursor(251,211);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Reset");    
  }
  else if(CurrentScreen==10){
    tft.setCursor(253,208);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print(">>>"); 
  }
  else{      
    tft.setCursor(263,208);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print(">>");
  }
    
  }  

  void PrintScreenLayout1(){

    tft.fillScreen(BLACK);
// Draw Rectangle frame
    tft.drawRect(5,3,312,192,WHITE);
    tft.drawRect(4,4,312,190,WHITE);

// Button Back
    tft.fillRect(5,198,74,40,DARKGREY);
    tft.drawRect(5,198,74,40,WHITE);
    tft.drawRect(4,199,74,38,WHITE);
    if(CurrentScreen==17){
       tft.setCursor(12,208);
       tft.setTextColor(BLACK);
       tft.setTextSize(3);
       tft.print("<<<");
    }
    else{    
       tft.setCursor(22,208);
       tft.setTextColor(BLACK);
       tft.setTextSize(3);
       tft.print("<<");
    }
   
// Button NEXT
    tft.fillRect(242,198,75,40,DARKGREY);
    tft.drawRect(242,198,75,40,WHITE);
    tft.drawRect(241,199,75,38,WHITE); 
    if(CurrentScreen!=17){  
        tft.setCursor(263,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print(">>");
  }  

// Button Down
  if(CurrentScreen!=30 && CurrentScreen!=32){
      tft.fillRect(84,198,74,40,DARKGREY);
      tft.drawRect(84,198,74,40,WHITE);
      tft.drawRect(83,199,74,38,WHITE);
  }
    if(CurrentScreen==3 || CurrentScreen==13 || CurrentScreen==19){
        tft.setCursor(92,210);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Reset");   
    }
    else if (CurrentScreen==2 || CurrentScreen==12){
        tft.setCursor(93,210);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Graf.");
      
    }

// Button UP
  if(CurrentScreen!=30 && CurrentScreen!=32){
      tft.fillRect(163,198,74,40,DARKGREY);
      tft.drawRect(163,198,74,40,WHITE);
      tft.drawRect(162,199,74,38,WHITE);
  }
     if(CurrentScreen==3){
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.setCursor(170,202);
        tft.print("T.Max");
        tft.setCursor(170,221);
        tft.print("T.Min");    
    }
     else if(CurrentScreen==13){
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.setCursor(170,202);
        tft.print("H.Max");
        tft.setCursor(170,221);
        tft.print("H.Min");    
    }

    else if (CurrentScreen==2 || CurrentScreen==12){
        
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.setCursor(177,210);
        tft.print("Reg.");      
    }
  } 

  void PrintScreenLayout2(){

   tft.fillScreen(BLACK);
// Draw Rectangle frame
   tft.drawRect(5,3,312,192,WHITE);
   tft.drawRect(4,4,312,190,WHITE);

// Button NEXT
    tft.fillRect(242,198,75,40,DARKGREY);
    tft.drawRect(242,198,75,40,WHITE);
    tft.drawRect(241,199,75,38,WHITE);
    if(CurrentScreen==1){
        //tft.setCursor(255,211);
        //tft.setTextColor(BLACK);
        //tft.setTextSize(2);
        //tft.print("Menu");
        tft.setCursor(263,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print(">>");
     }
     else if(CurrentScreen==0){
        tft.setCursor(253,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print(">>>");      
     }
     else{   
        tft.setCursor(263,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print(">>");
     }   

    // Button Back
    tft.fillRect(5,198,74,40,DARKGREY);
    tft.drawRect(5,198,74,40,WHITE);
    tft.drawRect(4,199,74,38,WHITE);
     if(CurrentScreen==1){
        tft.setCursor(15,211);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Info");
     }

// Button Down
  if(CurrentScreen==1){
     tft.fillRect(84,198,153,40,DARKGREY);
     tft.drawRect(84,198,153,40,WHITE);
     tft.drawRect(83,199,153,38,WHITE);
     tft.setCursor(100,211);
     tft.setTextColor(BLACK);
     tft.setTextSize(2);
     tft.print("Configurar"); 
  }
  else{
     tft.fillRect(84,198,74,40,DARKGREY);
     tft.drawRect(84,198,74,40,WHITE);
     tft.drawRect(83,199,74,38,WHITE);     
  }     
 
// Button UP
  if(CurrentScreen!=1){
     tft.fillRect(163,198,74,40,DARKGREY);
     tft.drawRect(163,198,74,40,WHITE);
     tft.drawRect(162,199,74,38,WHITE); 
  } 
}

 void PrintScreenLayout3(){

    tft.fillScreen(BLACK);
// Draw Rectangle frame
    tft.drawRect(5,3,312,192,WHITE);
    tft.drawRect(4,4,312,190,WHITE);

// Button Back
    tft.fillRect(5,198,74,40,DARKGREY);
    tft.drawRect(5,198,74,40,WHITE);
    tft.drawRect(4,199,74,38,WHITE);
    if(CurrentScreen==21){
        tft.setCursor(12,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print("<<<");
     }
     else{
        tft.setCursor(22,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print("<<");          
     }


// Button Down
    tft.fillRect(84,198,74,40,DARKGREY);
    tft.drawRect(84,198,74,40,WHITE);
    tft.drawRect(83,199,74,38,WHITE);    

// Button UP
    tft.fillRect(163,198,74,40,DARKGREY);
    tft.drawRect(163,198,74,40,WHITE);
    tft.drawRect(162,199,74,38,WHITE);    

// Button NEXT
    tft.fillRect(242,198,75,40,DARKGREY);
    tft.drawRect(242,198,75,40,WHITE);
    tft.drawRect(241,199,75,38,WHITE);
    if (CurrentScreen==24){
       tft.setCursor(253,208);
       tft.setTextColor(BLACK);
       tft.setTextSize(3);
       tft.print(">>>");    
    }
    
  } 

  void PrintScreenLayout4(){

    tft.fillScreen(BLACK);
    
// Desenhar rectanglo frame
    tft.drawRect(5,3,312,192,WHITE);
    tft.drawRect(4,4,312,190,WHITE);

// Button Back
    tft.fillRect(5,198,74,40,DARKGREY);
    tft.drawRect(5,198,74,40,WHITE);
    tft.drawRect(4,199,74,38,WHITE);    
    tft.setCursor(22,208);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print("<<");

// Button Down
    tft.fillRect(84,198,74,40,DARKGREY);
    tft.drawRect(84,198,74,40,WHITE);
    tft.drawRect(83,199,74,38,WHITE);  
   if(CurrentScreen==5 || CurrentScreen==15 || CurrentScreen==25 || CurrentScreen==26){
    tft.setTextColor(BLACK);   
    tft.setCursor(106,208);   
    tft.setTextSize(3);
    tft.print(">>");
    }
  else{
    tft.setTextColor(BLACK);   
    tft.setCursor(113,208);   
    tft.setTextSize(3);
    tft.print("-");     
  }

// Button UP
    tft.fillRect(163,198,74,40,DARKGREY);
    tft.drawRect(163,198,74,40,WHITE);
    tft.drawRect(162,199,74,38,WHITE);
    tft.setTextColor(BLACK);    
    tft.setCursor(192,208);
    tft.setTextSize(3);
    tft.print("+");

// Button NEXT 
    tft.fillRect(242,198,75,40,DARKGREY);
    tft.drawRect(242,198,75,40,WHITE);
    tft.drawRect(241,199,75,38,WHITE);
  if(CurrentScreen==4){     
      tft.setCursor(263,208);
      tft.setTextColor(BLACK);
      tft.setTextSize(3);
      tft.print(">>");    
  }
  else if(CurrentScreen==4){
        tft.setCursor(253,208);
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        tft.print(">>>");
     }   
    
}

// *************************** Função para Touch *****************************
 void AnyButtonPressed(){

     TSPoint p = ts.getPoint();
   
 if (p.z > MINPRESSURE && p.z < MAXPRESSURE){

    if(p.x>805 && p.x<875 && p.y>318 && p.y<669 && CurrentScreen==1){ // Botao Configigurar.
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=23;
      Screen23(); 
    }
    
   if(p.x>805 && p.x<875 && p.y>737 && p.y<883){ // Botão next
      ButtonNext=true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      ButtonNextPressed();  
    }
   if(p.x>805 && p.x<875 && p.y>113 && p.y<250){ // Botao Back
      ButtonBack=true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      ButtonBackPressed();    
    }
   if(p.x>805 && p.x<875 && p.y>531 && p.y<669 && CurrentScreen!=1){ // Botao up
      ButtonUp=true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT); 
      ButtonUpPressed();  
    }
   if(p.x>805 && p.x<875 && p.y>318 && p.y<453 && CurrentScreen!=1){ // Botao Down
      ButtonDown=true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      ButtonDownPressed();    
    }
 
   if(p.x>464 && p.x<551 && p.y>139 && p.y<442 && CurrentScreen==1){ // Botao Auto
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      MachineStatus=1;
      EEPROM.write(0,MachineStatus);
      PrintMachineStatus();    
    }
   if(p.x>464 && p.x<551 && p.y>537 && p.y<860 && CurrentScreen==1){ // Botao Manual
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      MachineStatus=0;
      EEPROM.write(0,MachineStatus);
      PrintMachineStatus();    
    }
    if(p.x>167 && p.x<267 && p.y>239 && p.y<760 && CurrentScreen==1){ // Clicar na Temperatura em Home Screen
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      TempHomePressed=true;
      CurrentScreen=21;
      Screen21();         
    }   
    if(p.x>646 && p.x<736 && p.y>129 && p.y<448 && CurrentScreen==1){ // Clicar na hora/data em Home Screen
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=8;
      Screen8();     
    }
    if(p.x>646 && p.x<736 && p.y>539 && p.y<862 && CurrentScreen==1){ // Clicar no Estado dos Outputs em Home Screen
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=17;
      Screen17();         
    }
    if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==4){ // Clicar na Temperatura Maxima
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      TMaxPressed=true;
      TMinPressed=false;
      Screen4UpdateTMax();
      Screen4UpdateTMin();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==4){ // Clicar na Temperatura Minima
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      TMinPressed=true;
      TMaxPressed=false;
      Screen4UpdateTMax();
      Screen4UpdateTMin();
    }
    if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==14){ // Clicar na Humidade Maxima
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      HMaxPressed=true;
      HMinPressed=false;
      Screen14UpdateHMax();
      Screen14UpdateHMin();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==14){ // Clicar na Humidade Minima
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      HMinPressed=true;
      HMaxPressed=false;
      Screen14UpdateHMax();
      Screen14UpdateHMin();
    }
    if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==6){ // Clicar na Temperatura Directa 
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      TDirectPressed=true;
      TCalibPressed=false;
      Screen6UpdateTDirect();
      Screen6UpdateTCalib();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==6){ // Clicar na Temperatura Calibrada
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      TCalibPressed=true;
      TDirectPressed=false;
      Screen6UpdateTDirect();
      Screen6UpdateTCalib();
    } 
    if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==16){ // Clicar na Humidade Directa 
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      HDirectPressed=true;
      HCalibPressed=false;
      Screen16UpdateHDirect();
      Screen16UpdateHCalib();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==16){ // Clicar na Humidade Calibrada
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      HCalibPressed=true;
      HDirectPressed=false;
      Screen16UpdateHDirect();
      Screen16UpdateHCalib();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==8){ // Clicar dia do mês
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      DayPressed=true;
      DayOfWeekPressed=false;
      Screen8UpdateDayOfWeek();
      Screen8UpdateDay();
    }
     if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==9){ // Clicar em Mês
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      MonthPressed=true;
      YearPressed=false;
      Screen9UpdateMonth();
      Screen9UpdateYear();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==9){ // Clicar em Ano
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      YearPressed=true;
      MonthPressed=false;
      Screen9UpdateMonth();
      Screen9UpdateYear();
    }
     if(p.x>470 && p.x<717 && p.y>141 && p.y<439 && CurrentScreen==10){ // Clicar em Hora
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      HourPressed=true;
      MinutePressed=false;
      Screen10UpdateHour();
      Screen10UpdateMinute();
    }
    if(p.x>470 && p.x<717 && p.y>533 && p.y<860 && CurrentScreen==10){ // Clicar em Minutos
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      MinutePressed=true;
      HourPressed=false;
      Screen10UpdateHour();
      Screen10UpdateMinute();
    }
    if(p.x>305 && p.x<372 && p.y>363 && p.y<615 && CurrentScreen==21){ //Menu: Temperatura/Humidade: Botao 1
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      if(TempHomePressed==true){
        CurrentScreen=3;
        Screen3();           
      }
      else if(HumHomePressed==true){
        CurrentScreen=13;
        Screen13();           
      }
    }

    if(p.x>466 && p.x<548 && p.y>187 && p.y<800 && CurrentScreen==21){ //Menu: Temperatura/Humidade: Botao 2
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      AuxHourScreen20=Hour;
      CurrentScreen=20;
      Screen20();
    }

    if(p.x>634 && p.x<712 && p.y>187 && p.y<800 && CurrentScreen==21){ //Menu: Temperatura/Humidade: Botao 3
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      if(TempHomePressed==true){
        CurrentScreen=2;
        Screen2();           
      }
      else if(HumHomePressed==true){
        CurrentScreen=12;
        Screen12();           
      }
    } 

    if(p.x>305 && p.x<372 && p.y>187 && p.y<800 && CurrentScreen==23){ //Config Menu 1: botao 1
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=6;
      Screen6();           
    }

    if(p.x>466 && p.x<548 && p.y>187 && p.y<800 && CurrentScreen==23){ //Config Menu 1: botao 2
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=11;
      Screen11();
    }

    if(p.x>634 && p.x<712 && p.y>187 && p.y<800 && CurrentScreen==23){ //Config Menu 1: botao 3
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=22;
      Screen22();           
    } 

    if(p.x>298 && p.x<333 && p.y>141 && p.y<437 && CurrentScreen==30){ // Programar Saida RL3: Segunda
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }

        if(RL3ConfigMon==0){
          RL3ConfigMon=1;
          EEPROM.write(19,RL3ConfigMon);         
        }
        else{
          RL3ConfigMon=0;
          EEPROM.write(19,RL3ConfigMon);
        }
        
        if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();
    }

    if(p.x>298 && p.x<333 && p.y>551 && p.y<847 && CurrentScreen==30){ // Programar Saida RL3: Terça
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigTue==0){
          RL3ConfigTue=1;
          EEPROM.write(20,RL3ConfigTue);         
        }
        else{
          RL3ConfigTue=0;
          EEPROM.write(20,RL3ConfigTue);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();          
    } 

    if(p.x>421 && p.x<471 && p.y>133 && p.y<439 && CurrentScreen==30){ // Programar Saida RL3: Quarta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigWed==0){
          RL3ConfigWed=1;
          EEPROM.write(21,RL3ConfigWed);         
        }
        else{
          RL3ConfigWed=0;
          EEPROM.write(21,RL3ConfigWed);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();           
    } 

    if(p.x>421 && p.x<471 && p.y>557 && p.y<850 && CurrentScreen==30){ // Programar Saida RL3: Quinta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigThu==0){
          RL3ConfigThu=1;
          EEPROM.write(22,RL3ConfigThu);         
        }
        else{
          RL3ConfigThu=0;
          EEPROM.write(22,RL3ConfigThu);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();           
    }

    if(p.x>558 && p.x<600 && p.y>136 && p.y<430 && CurrentScreen==30){ // Programar Saida RL3: Sexta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigFri==0){
          RL3ConfigFri=1;
          EEPROM.write(23,RL3ConfigFri);         
        }
        else{
          RL3ConfigFri=0;
          EEPROM.write(23,RL3ConfigFri);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();           
    }

    if(p.x>558 && p.x<600 && p.y>547 && p.y<845 && CurrentScreen==30){ // Programar Saida RL3: Sábado
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigSat==0){
          RL3ConfigSat=1;
          EEPROM.write(24,RL3ConfigSat);         
        }
        else{
          RL3ConfigSat=0;
          EEPROM.write(24,RL3ConfigSat);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();            
    }

    if(p.x>682 && p.x<732 && p.y>136 && p.y<444 && CurrentScreen==30){ // Programar Saida RL3: Domingo
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL3ConfigOff==1){
          RL3ConfigOff=0;
          EEPROM.write(26,RL3ConfigOff);
        }       

        if(RL3ConfigSun==0){
          RL3ConfigSun=1;
          EEPROM.write(25,RL3ConfigSun);         
        }
        else{
          RL3ConfigSun=0;
          EEPROM.write(25,RL3ConfigSun);  
        }

       if(RL3ConfigMon==0 && RL3ConfigTue==0 && RL3ConfigWed==0 && RL3ConfigThu==0 && RL3ConfigFri==0 && RL3ConfigSat==0 && RL3ConfigSun==0 && RL3ConfigOff==0){
          RL3ConfigOff=1;
          EEPROM.write(26,RL3ConfigOff);
        }
        
        Screen30Update();           
    } 

    if(p.x>682 && p.x<732 && p.y>537 && p.y<842 && CurrentScreen==30){ // Programar Saida RL3: Desligado
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      
      if(RL3ConfigOff==0){
          RL3ConfigMon=0;
          RL3ConfigTue=0;
          RL3ConfigWed=0;
          RL3ConfigThu=0;
          RL3ConfigFri=0;
          RL3ConfigSat=0;
          RL3ConfigSun=0;     
          RL3ConfigOff=1;
  
          EEPROM.write(19,RL3ConfigMon);
          EEPROM.write(20,RL3ConfigTue);
          EEPROM.write(21,RL3ConfigWed);
          EEPROM.write(22,RL3ConfigThu);
          EEPROM.write(23,RL3ConfigFri);
          EEPROM.write(24,RL3ConfigSat);
          EEPROM.write(25,RL3ConfigSun);  
          EEPROM.write(26,RL3ConfigOff);
       }
        
        Screen30Update();              
    }
    
    if(p.x>385 && p.x<503 && p.y>131 && p.y<436 && CurrentScreen==31){ // RL3 Horas para ligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL3HourOnPressed = true;
      RL3MinuteOnPressed = false;
      RL3HourOffPressed = false;
      RL3MinuteOffPressed = false;
      Screen31UpdateHourOn();
      Screen31UpdateMinuteOn();
      Screen31UpdateHourOff();
      Screen31UpdateMinuteOff();           
    }
    
    if(p.x>586 && p.x<714 && p.y>126 && p.y<443 && CurrentScreen==31){ // RL3 Minutos para ligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL3HourOnPressed = false;
      RL3MinuteOnPressed = true;
      RL3HourOffPressed = false;
      RL3MinuteOffPressed = false;
      Screen31UpdateHourOn();
      Screen31UpdateMinuteOn();
      Screen31UpdateHourOff();
      Screen31UpdateMinuteOff();             
    }
    
    if(p.x>389 && p.x<495 && p.y>531 && p.y<858 && CurrentScreen==31){ // RL3 Horas para Desligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL3HourOnPressed = false;
      RL3MinuteOnPressed = false;
      RL3HourOffPressed = true;
      RL3MinuteOffPressed = false;
      Screen31UpdateHourOn();
      Screen31UpdateMinuteOn();
      Screen31UpdateHourOff();
      Screen31UpdateMinuteOff();           
    }
    
    if(p.x>588 && p.x<722 && p.y>526 && p.y<855 && CurrentScreen==31){ // RL3 Minutos para Desligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL3HourOnPressed = false;
      RL3MinuteOnPressed = false;
      RL3HourOffPressed = false;
      RL3MinuteOffPressed = true;            
      Screen31UpdateHourOn();
      Screen31UpdateMinuteOn();
      Screen31UpdateHourOff();
      Screen31UpdateMinuteOff();            
    }
                      
    if(p.x>298 && p.x<333 && p.y>141 && p.y<437 && CurrentScreen==32){ // Programar Saida RL4: Segunda
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }

        if(RL4ConfigMon==0){
          RL4ConfigMon=1;
          EEPROM.write(27,RL4ConfigMon);         
        }
        else{
          RL4ConfigMon=0;
          EEPROM.write(27,RL4ConfigMon);
        }
        
        if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();
    }

    if(p.x>298 && p.x<333 && p.y>551 && p.y<847 && CurrentScreen==32){ // Programar Saida RL4: Terça
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigTue==0){
          RL4ConfigTue=1;
          EEPROM.write(28,RL4ConfigTue);         
        }
        else{
          RL4ConfigTue=0;
          EEPROM.write(28,RL4ConfigTue);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();          
    } 

    if(p.x>421 && p.x<471 && p.y>133 && p.y<439 && CurrentScreen==32){ // Programar Saida RL4: Quarta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigWed==0){
          RL4ConfigWed=1;
          EEPROM.write(29,RL4ConfigWed);         
        }
        else{
          RL4ConfigWed=0;
          EEPROM.write(29,RL4ConfigWed);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();           
    } 

    if(p.x>421 && p.x<471 && p.y>557 && p.y<850 && CurrentScreen==32){ // Programar Saida RL4: Quinta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigThu==0){
          RL4ConfigThu=1;
          EEPROM.write(30,RL4ConfigThu);         
        }
        else{
          RL4ConfigThu=0;
          EEPROM.write(30,RL4ConfigThu);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();           
    }

    if(p.x>558 && p.x<600 && p.y>136 && p.y<430 && CurrentScreen==32){ // Programar Saida RL4: Sexta
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigFri==0){
          RL4ConfigFri=1;
          EEPROM.write(31,RL4ConfigFri);         
        }
        else{
          RL4ConfigFri=0;
          EEPROM.write(31,RL4ConfigFri);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();           
    }

    if(p.x>558 && p.x<600 && p.y>547 && p.y<845 && CurrentScreen==32){ // Programar Saida RL4: Sábado
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigSat==0){
          RL4ConfigSat=1;
          EEPROM.write(32,RL4ConfigSat);         
        }
        else{
          RL4ConfigSat=0;
          EEPROM.write(32,RL4ConfigSat);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();            
    }

    if(p.x>682 && p.x<732 && p.y>136 && p.y<444 && CurrentScreen==32){ // Programar Saida RL4: Domingo
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if(RL4ConfigOff==1){
          RL4ConfigOff=0;
          EEPROM.write(34,RL4ConfigOff);
        }       

        if(RL4ConfigSun==0){
          RL4ConfigSun=1;
          EEPROM.write(33,RL4ConfigSun);         
        }
        else{
          RL4ConfigSun=0;
          EEPROM.write(33,RL4ConfigSun);  
        }

       if(RL4ConfigMon==0 && RL4ConfigTue==0 && RL4ConfigWed==0 && RL4ConfigThu==0 && RL4ConfigFri==0 && RL4ConfigSat==0 && RL4ConfigSun==0 && RL4ConfigOff==0){
          RL4ConfigOff=1;
          EEPROM.write(34,RL4ConfigOff);
        }
        
        Screen32Update();           
    } 

    if(p.x>682 && p.x<732 && p.y>537 && p.y<842 && CurrentScreen==32){ // Programar Saida RL4: Desligado
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      
      if(RL4ConfigOff==0){
          RL4ConfigMon=0;
          RL4ConfigTue=0;
          RL4ConfigWed=0;
          RL4ConfigThu=0;
          RL4ConfigFri=0;
          RL4ConfigSat=0;
          RL4ConfigSun=0;     
          RL4ConfigOff=1;
  
          EEPROM.write(27,RL4ConfigMon);
          EEPROM.write(28,RL4ConfigTue);
          EEPROM.write(29,RL4ConfigWed);
          EEPROM.write(30,RL4ConfigThu);
          EEPROM.write(31,RL4ConfigFri);
          EEPROM.write(32,RL4ConfigSat);
          EEPROM.write(33,RL4ConfigSun);  
          EEPROM.write(34,RL4ConfigOff);
       }
        
        Screen32Update();              
    }
    
    if(p.x>385 && p.x<503 && p.y>131 && p.y<436 && CurrentScreen==33){ // RL4 Horas para ligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL4HourOnPressed = true;
      RL4MinuteOnPressed = false;
      RL4HourOffPressed = false;
      RL4MinuteOffPressed = false;
      Screen33UpdateHourOn();
      Screen33UpdateMinuteOn();
      Screen33UpdateHourOff();
      Screen33UpdateMinuteOff();           
    }
    
    if(p.x>586 && p.x<714 && p.y>126 && p.y<443 && CurrentScreen==33){ // RL4 Minutos para ligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL4HourOnPressed = false;
      RL4MinuteOnPressed = true;
      RL4HourOffPressed = false;
      RL4MinuteOffPressed = false;
      Screen33UpdateHourOn();
      Screen33UpdateMinuteOn();
      Screen33UpdateHourOff();
      Screen33UpdateMinuteOff();             
    }
    
    if(p.x>389 && p.x<495 && p.y>531 && p.y<858 && CurrentScreen==33){ // RL4 Horas para Desligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL4HourOnPressed = false;
      RL4MinuteOnPressed = false;
      RL4HourOffPressed = true;
      RL4MinuteOffPressed = false;
      Screen33UpdateHourOn();
      Screen33UpdateMinuteOn();
      Screen33UpdateHourOff();
      Screen33UpdateMinuteOff();           
    }
    
    if(p.x>588 && p.x<722 && p.y>526 && p.y<855 && CurrentScreen==33){ // RL4 Minutos para Desligar
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      RL4HourOnPressed = false;
      RL4MinuteOnPressed = false;
      RL4HourOffPressed = false;
      RL4MinuteOffPressed = true;            
      Screen33UpdateHourOn();
      Screen33UpdateMinuteOn();
      Screen33UpdateHourOff();
      Screen33UpdateMinuteOff();            
    }
    
    if(p.x>305 && p.x<372 && p.y>187 && p.y<800 && CurrentScreen==24){ //Config Menu 2: botao 1
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=30;
      Screen30();        
    }

    if(p.x>466 && p.x<548 && p.y>187 && p.y<800 && CurrentScreen==24){ //Config Menu 2: botao 2
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=32;
      Screen32();       
    }

    if(p.x>634 && p.x<712 && p.y>187 && p.y<800 && CurrentScreen==24){ //Config Menu 2: botao 3
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      CurrentScreen=27;
      Screen27();           
    }
                          
    delay(150); 
     
    if(ScreenSaverTimeout>0){ // Protecao de Ecra - Camar Ecra 1 quando touch for pressionado
      if(ScreenSaverTimeoutCnt>=ScreenSaverTimeout*60){
          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          ScreenSaverTimeoutCnt=0;
          ScreenSaverDelay=5;
          CurrentScreen=1;
          Screen1();
      }
    }             
    ScreenSaverTimeoutCnt=0;
    ScreenSaverDelay=5;
 }     
}

  void ButtonNextPressed(){
    
// Caso Botão next seja Selecionado
  if(ButtonNext==true){  
     switch (CurrentScreen) 
      {
       case 0:
            CurrentScreen=1;
            Screen1();
       break;                   
       case 1:         
          if (MachineStatus==1){CurrentScreen=4;Screen4();} 
          if (MachineStatus==0){CurrentScreen=5;Screen5();}
       break;              
       case 2:
       break;                
       case 3:
          CurrentScreen=21;
          Screen21();
       break;                
       case 4:
          CurrentScreen=1;
          Screen1();
       break;               
       case 5:
          if(RL3ConfigOff==0){
              CurrentScreen=25;
              Screen25();
          }
          else if(RL4ConfigOff==0){
              CurrentScreen=26;
              Screen26();
          }
          else{
              CurrentScreen=1;
              Screen1();
          }          
       break;
       case 6:
           CurrentScreen=7;
           Screen7();
           TCalibPressed=false;
           TDirectPressed=false;        
       break;
       case 7:
           CurrentScreen=23;
           Screen23();        
       break;
       case 8:
           DayOfWeekPressed=false;
           DayPressed=false;
           CurrentScreen=9;
           Screen9();        
       break;
       case 9:
           MonthPressed=false;
           YearPressed=false;
           CurrentScreen=10;
           Screen10();        
       break;
       case 10:
           HourPressed=false;
           MinutePressed=false;
           CurrentScreen=1;
           Screen1();        
       break;
       case 11:
          if(RL3ConfigOff==0){
              CurrentScreen=28;
              Screen28();
          }
          else if(RL4ConfigOff==0){
              CurrentScreen=29;
              Screen29();
          }
          else{
              CurrentScreen=23;
              Screen23();
          } 
       break;
       case 12:
       break; 
       case 13:       
           CurrentScreen=19;
           Screen19();        
       break;             
       case 14:
          CurrentScreen=1;
          Screen1();
       break;
       case 15:
          CurrentScreen=25;
          Screen25();
       break;       
       case 16:
          CurrentScreen=7;
          Screen7();
          HCalibPressed=false;
          HDirectPressed=false;        
       break;
       case 17:
       break;       
       case 18:
          CurrentScreen=28;
          Screen28();
       break;
       case 19:
          CurrentScreen=21;
          Screen21();       
       break;
       case 20:
          TempEventDataReset();
          HumEventDataReset();
       break; 
       case 23:
          CurrentScreen=24;
          Screen24();
       break;
       case 24:
          CurrentScreen=1;
          Screen1();
       break;
       case 25:       
          if(RL4ConfigOff==0){
              CurrentScreen=26;
              Screen26();
          }
          else{
              CurrentScreen=1;
              Screen1();
          } 
       break;
       case 26:
          CurrentScreen=1;
          Screen1();
       break;
       case 27:
           CurrentScreen=34;
           Screen34();
       break; 
       case 28:
          if(RL4ConfigOff==0){
              CurrentScreen=29;
              Screen29();
          }
          else{
              CurrentScreen=23;
              Screen23();
          } 
       break;
       case 29:
          CurrentScreen=23;
          Screen23();
       break;
       case 30:
          CurrentScreen=31;
          Screen31();
       break;
       case 31:
          CurrentScreen=24;
          Screen24();
          RL3HourOnPressed = false;
          RL3MinuteOnPressed = false;
          RL3HourOffPressed = false;
          RL3MinuteOffPressed = false;          
       break; 
       case 32:
          CurrentScreen=33;
          Screen33();
       break;
       case 33:
          CurrentScreen=24;
          Screen24();
          RL4HourOnPressed = false;
          RL4MinuteOnPressed = false;
          RL4HourOffPressed = false;
          RL4MinuteOffPressed = false;          
       break;
       case 34:
          CurrentScreen=24;
          Screen24();
       break;                                                                                           
      }          
          ButtonNext=false;                     
  }  
 }

  void ButtonBackPressed(){

// Caso Botão seja for Selecionado
  if(ButtonBack==true){  
     switch (CurrentScreen) 
      {
       case 0:
       break;                           
       case 1:
          CurrentScreen=0;
          Screen0();
       break;              
       case 2:
          CurrentScreen=21;
          Screen21();
       break;                
       case 3:
          CurrentScreen=21;
          Screen21();
       break;                
       case 4:
          TMaxPressed=false;
          TMinPressed=false;
          CurrentScreen=1;
          Screen1();
       break;               
       case 5:
          CurrentScreen=1;
          Screen1();               
       break;
       case 6:
          CurrentScreen=23;
          Screen23();
          TCalibPressed=false;
          TDirectPressed=false;              
       break;
       case 7:
          CurrentScreen=6;
          Screen6();
       break;
       case 8:
          DayOfWeekPressed=false;
          DayPressed=false;
          CurrentScreen=1;
          Screen1();
       break;
       case 9:
          MonthPressed=false;
          YearPressed=false;       
          CurrentScreen=8;
          Screen8();
       break;
       case 10:
          HourPressed=false;
          MinutePressed=false;       
          CurrentScreen=9;
          Screen9();
       break;
       case 11:
          CurrentScreen=23;
          Screen23();
       break;
       case 12:
          CurrentScreen=21;
          Screen21();      
       break; 
       case 13:
          CurrentScreen=21;
          Screen21();        
       break;             
       case 14:
          CurrentScreen=4;
          Screen4();
       break;
       case 16:
          CurrentScreen=6;
          Screen6();
          HCalibPressed=false;
          HDirectPressed=false; 
       break;
       case 17:
          CurrentScreen=1;
          Screen1();
       break;       
       case 18:
          CurrentScreen=11;
          Screen11();
       break; 
       case 15:
          CurrentScreen=5;
          Screen5();
       break;
       case 19:
          if(TempHomePressed==true){CurrentScreen=3;Screen3();}
          if(HumHomePressed==true){CurrentScreen=13;Screen13();}   
       break;
       case 20:
          CurrentScreen=21;
          Screen21();
       break;
       case 21:
          CurrentScreen=1;
          Screen1();
          TempHomePressed=false; 
          HumHomePressed=false;                       
       break; 
       case 22:
          CurrentScreen=23;
          Screen23();
       break;
       case 23:
          CurrentScreen=1;
          Screen1();
       break; 
       case 24:
          CurrentScreen=23;
          Screen23();
       break; 
       case 25:
          CurrentScreen=5;
          Screen5();
       break; 
       case 26:
          if(RL3ConfigOff==0){
              CurrentScreen=25;
              Screen25();
          }
          else{
              CurrentScreen=5;
              Screen5();
          } 
       break; 
       case 27:
          CurrentScreen=24;
          Screen24();
       break;
       case 28:
          CurrentScreen=11;
          Screen11();
       break;
       case 29:
          if(RL3ConfigOff==0){
              CurrentScreen=28;
              Screen28();
          }
          else{
              CurrentScreen=11;
              Screen11();
          } 
       break;
       case 30:
          CurrentScreen=24;
          Screen24();
       break;
       case 31:
          CurrentScreen=30;
          Screen30();
          RL3HourOnPressed = false;
          RL3MinuteOnPressed = false;
          RL3HourOffPressed = false;
          RL3MinuteOffPressed = false;
       break;
       case 32:
          CurrentScreen=24;
          Screen24();
       break;
       case 33:
          CurrentScreen=32;
          Screen32();
          RL4HourOnPressed = false;
          RL4MinuteOnPressed = false;
          RL4HourOffPressed = false;
          RL4MinuteOffPressed = false;
       break;
       case 34:
          CurrentScreen=27;
          Screen27();
       break;                                                                                        
      }          
          ButtonBack=false;
  } 
 }

void ButtonUpPressed(){

// Caso Botão Up seja Selecionado
  if(ButtonUp==true){  
     switch (CurrentScreen) 
      {                   
       case 1:
           //CurrentScreen=23;
           //Screen23();               
       break;              
       case 2:
       break;                
       case 3:
          if(Graph_TMax_TMin==0){
            Graph_TMax_TMin=1;
            EEPROM.write(7,Graph_TMax_TMin);
          }
          else{
            Graph_TMax_TMin=0;
            EEPROM.write(7,Graph_TMax_TMin);
          }
          CurrentScreen=3;
          Screen3();
       break;                
       case 4:
          if(TMinPressed==true && TemperatureMin < TemperatureMax-1){
              TemperatureMin++;
              EEPROM.write(2,TemperatureMin);
              Screen4UpdateTMin();
          }
          if(TMaxPressed==true && TemperatureMax <130){
            TemperatureMax++;
            EEPROM.write(1,TemperatureMax);
            Screen4UpdateTMax();            
          }
       break;               
       case 5:
          if(MachineStatus == 0 && TemperatureControl==1){digitalWrite(DO_Temperature,HIGH);}
          if(MachineStatus == 0 && TemperatureControl==2){digitalWrite(DO_Temperature,LOW);}
          PrintOutputStatus();
       break;
       case 6:
          if(TCalibPressed==true && Val_TempCalib < 125){
             Val_TempCalibAux++;
             if(Val_TempCalibAux>9){
                Val_TempCalib++;
                Val_TempCalibAux=0;
             }
            EEPROM.update(6,Val_TempCalib);
            EEPROM.update(45,Val_TempCalibAux);
            Screen6UpdateTCalib();
          }
          if(TDirectPressed==true && Val_TempDirect < 125){
             Val_TempDirectAux++;
             if(Val_TempDirectAux>9){
                Val_TempDirect++;
                Val_TempDirectAux=0;
             }
            EEPROM.update(5,Val_TempDirect);
            EEPROM.update(44,Val_TempDirectAux);
            Screen6UpdateTDirect();            
          }     
       break;
       case 7:          
          if(TempHumReadInterval/1000 < 30){
            TempHumReadInterval = TempHumReadInterval+1000;
            EEPROM.write(3,TempHumReadInterval/1000);
            Screen7UpdateTempInterval();
          }           
       break;
       case 8: 
          if(DayPressed==true){
            Day++;
            if(Day>=32){Day=1;}
            Screen8UpdateDay();
          }
          if(DayPressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 9: 
          if(MonthPressed==true){
            Month++;
            if(Month>=13){Month=1;}
            Screen9UpdateMonth();
          }
          if(YearPressed==true){
            Year++;
            Screen9UpdateYear();            
          } 
          if(MonthPressed==true || YearPressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 10:
          if(HourPressed==true){
            Hour++;
            if(Hour>=24){Hour=0;}
            Screen10UpdateHour();
          }
          if(MinutePressed==true){
            Minute++;
            if(Minute>=60){Minute=0;}
            Screen10UpdateMinute();            
          } 
          if(HourPressed==true || MinutePressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 11:
          if(TemperatureControl<2){
            TemperatureControl++;
             EEPROM.write(4,TemperatureControl);
             Screen11Update();
          }
       break;
       case 12:       
       break;       
       case 13:
          if(Graph_HMax_HMin==0){
            Graph_HMax_HMin=1;
            EEPROM.write(13,Graph_HMax_HMin);        
          }
          else{
            Graph_HMax_HMin=0;
            EEPROM.write(13,Graph_HMax_HMin);
          }
          CurrentScreen=13;
          Screen13();
       break;        
       case 14:
          if(HMinPressed==true && HumidityMin < HumidityMax-2){
             HumidityMin++;
             EEPROM.write(9,HumidityMin);
             Screen14UpdateHMin();
          }
          if(HMaxPressed==true && HumidityMax <100){
            HumidityMax++;
            EEPROM.write(8,HumidityMax);
            Screen14UpdateHMax();            
          }
       break;
       case 15:
          if(MachineStatus == 0 && HumidityControl==1){digitalWrite(DO_Humidity,HIGH);}
          if(MachineStatus == 0 && HumidityControl==2){digitalWrite(DO_Humidity,LOW);}
          PrintOutputStatus();
       break;       
       case 16:
          if(HCalibPressed==true && Val_HumCalib < 100){
            Val_HumCalib++;
            EEPROM.write(11,Val_HumCalib);
            Screen16UpdateHCalib();
          }
          if(HDirectPressed==true && Val_HumDirect < 100){
            Val_HumDirect++;
            EEPROM.write(10,Val_HumDirect);
            Screen16UpdateHDirect();            
          }     
       break;
       case 18:
          if(HumidityControl<2){
            HumidityControl++;
            EEPROM.write(12,HumidityControl);
            Screen18Update();
          }
       break; 
       case 20:
          AuxHourScreen20=AuxHourScreen20+1;
          if(AuxHourScreen20>=24){AuxHourScreen20=0;}
          CurrentScreen=20;
          Screen20();
       break; 
       case 22:
          if(EventsRegInterval==0){EventsRegInterval=5;}
          //else if(EventsRegInterval==3){EventsRegInterval=5;}                 
          else if(EventsRegInterval==5){EventsRegInterval=10;}
          else if(EventsRegInterval==10){EventsRegInterval=15;}
          else if(EventsRegInterval==15){EventsRegInterval=20;}
          else if(EventsRegInterval==20){EventsRegInterval=30;}
          else if(EventsRegInterval==30){EventsRegInterval=60;}
          else if(EventsRegInterval==60){EventsRegInterval=0;}
          else{EventsRegInterval=0;}
          EEPROM.write(15,EventsRegInterval);
          Screen22Update();
       break;
       case 25:
          if(MachineStatus == 0 && RL3OutputControl==1){digitalWrite(DO_RL3,HIGH);}
          if(MachineStatus == 0 && RL3OutputControl==2){digitalWrite(DO_RL3,LOW);}
          PrintOutputStatus();
       break;
       case 26:
          if(MachineStatus == 0 && RL4OutputControl==1){digitalWrite(DO_RL4,HIGH);}
          if(MachineStatus == 0 && RL4OutputControl==2){digitalWrite(DO_RL4,LOW);}
          PrintOutputStatus();
       break;
       case 27:
          if(DisplayOutputsScreen1==0){
            DisplayOutputsScreen1=1;
            EEPROM.write(18,DisplayOutputsScreen1);
          }
          else{
            DisplayOutputsScreen1=1;
            EEPROM.write(18,DisplayOutputsScreen1);
          }
          Screen27Update();
       break;
       case 28:
          if(RL3OutputControl<2){
            RL3OutputControl++;
            EEPROM.write(16,RL3OutputControl);
            Screen28Update();
          }
       break; 
       case 29:
          if(RL4OutputControl<2){
            RL4OutputControl++;
            EEPROM.write(17,RL4OutputControl);
            Screen29Update();
          }
       break;
       case 31:
            if(RL3HourOnPressed == true){
              if(RL3ConfigHourOn<23){RL3ConfigHourOn++;}else{RL3ConfigHourOn=0;}
              EEPROM.write(35,RL3ConfigHourOn);
              Screen31UpdateHourOn();
            }
            else if(RL3MinuteOnPressed == true){
              if(RL3ConfigMinuteOn<59){RL3ConfigMinuteOn++;}else{RL3ConfigMinuteOn=0;}
              EEPROM.write(36,RL3ConfigMinuteOn);
              Screen31UpdateMinuteOn();              
            }            
            else if(RL3HourOffPressed == true){          
              if(RL3ConfigHourOff<23){RL3ConfigHourOff++;}else{RL3ConfigHourOff=0;}         
              EEPROM.write(37,RL3ConfigHourOff);
              Screen31UpdateHourOff();              
            }
            else if(RL3MinuteOffPressed == true){
              if(RL3ConfigMinuteOff<59){RL3ConfigMinuteOff++;}else{RL3ConfigMinuteOff=0;}         
              EEPROM.write(38,RL3ConfigMinuteOff);
              Screen31UpdateMinuteOff();               
            }                   
       break;
       case 33:
            if(RL4HourOnPressed == true){
              if(RL4ConfigHourOn<23){RL4ConfigHourOn++;}else{RL4ConfigHourOn=0;}
              EEPROM.write(39,RL4ConfigHourOn);
              Screen33UpdateHourOn();
            }
            else if(RL4MinuteOnPressed == true){
              if(RL4ConfigMinuteOn<59){RL4ConfigMinuteOn++;}else{RL4ConfigMinuteOn=0;}
              EEPROM.write(40,RL4ConfigMinuteOn);
              Screen33UpdateMinuteOn();              
            }            
            else if(RL4HourOffPressed == true){          
              if(RL4ConfigHourOff<23){RL4ConfigHourOff++;}else{RL4ConfigHourOff=0;}         
              EEPROM.write(41,RL4ConfigHourOff);
              Screen33UpdateHourOff();              
            }
            else if(RL4MinuteOffPressed == true){
              if(RL4ConfigMinuteOff<59){RL4ConfigMinuteOff++;}else{RL4ConfigMinuteOff=0;}         
              EEPROM.write(42,RL4ConfigMinuteOff);
              Screen33UpdateMinuteOff();               
            }                   
       break;
       case 34:
            if(ScreenSaverTimeout <90){
              ScreenSaverTimeout = ScreenSaverTimeout+5;
              EEPROM.write(43,ScreenSaverTimeout);
              Screen34Update();
              ScreenSaverTimeoutCnt=0;            
          }
       break;                              
      }          
      ButtonUp=false;                
  }  
}

 void ButtonDownPressed(){

// Caso Botão Down seja Selecionado
  if(ButtonDown==true){  
     switch (CurrentScreen) 
      {
       case 1:
           //CurrentScreen=23;
           //Screen23();          
       break;         
       case 2: 
       break;                            
       case 3:
          GraphTempValuesReset();       
          GraphHumValuesReset();
       break;                
       case 4:
          if(TMinPressed==true && TemperatureMin>=1 ){
            TemperatureMin--;
            EEPROM.write(2,TemperatureMin);
            Screen4UpdateTMin();           
          }
          if(TMaxPressed==true && TemperatureMax > TemperatureMin+1){
            TemperatureMax--;
            EEPROM.write(1,TemperatureMax);
            Screen4UpdateTMax();
          }
       break;               
       case 5:
           if(MachineStatus == 0 && TemperatureControl==1){digitalWrite(DO_Temperature,LOW);}
           if(MachineStatus == 0 && TemperatureControl==2){digitalWrite(DO_Temperature,HIGH);}
           PrintOutputStatus();
       break;
       case 6:
          if(TCalibPressed==true && Val_TempCalib>1){     
             Val_TempCalibAux--;
             if(Val_TempCalibAux<0){
                Val_TempCalib--;
                Val_TempCalibAux=9;
             }
            EEPROM.update(6,Val_TempCalib);
            EEPROM.update(45,Val_TempCalibAux);
            Screen6UpdateTCalib();           
          }
          if(TDirectPressed==true && Val_TempDirect>1){
             Val_TempDirectAux--;
             if(Val_TempDirectAux<0){
                Val_TempDirect--;
                Val_TempDirectAux=9;
             }
            EEPROM.update(5,Val_TempDirect);
            EEPROM.update(44,Val_TempDirectAux);
            Screen6UpdateTDirect(); 
          }        
       break; 
       case 7:
          if(TempHumReadInterval/1000 >1){
            TempHumReadInterval = TempHumReadInterval-1000;
            EEPROM.write(3,TempHumReadInterval/1000);
            Screen7UpdateTempInterval();}
       break;
       case 8: 
          if(DayPressed==true){
            Day--;
            if(Day<=-1){Day=31;}
            Screen8UpdateDay();
          }
          if(DayPressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 9:      
         if(MonthPressed==true){
            Month--;
            if(Month<=-1){Month=12;}
            Screen9UpdateMonth();
         }
         if(YearPressed==true){
           Year--;
           Screen9UpdateYear();            
         } 
         if(MonthPressed==true || YearPressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 10:
         if(HourPressed==true){
           Hour--;
           if(Hour<=-1){Hour=23;}
           Screen10UpdateHour();
         }
         if(MinutePressed==true){
           Minute--;
           if(Minute<=-1){Minute=59;}
           Screen10UpdateMinute();            
         } 
         if(HourPressed==true || MinutePressed==true){rtc.adjust(DateTime(Year,Month,Day,Hour,Minute,30));}
       break;
       case 11:
          if(TemperatureControl>1){
             TemperatureControl--;
             EEPROM.write(4,TemperatureControl);
             Screen11Update();
          }
       break;
       case 12:
       break;
       case 13:
          GraphTempValuesReset();      
          GraphHumValuesReset();       
       break;
       case 14:
          if(HMinPressed==true && HumidityMin>=2 ){
            HumidityMin--;
            EEPROM.write(9,HumidityMin);
            Screen14UpdateHMin();           
            }
          if(HMaxPressed==true && HumidityMax > HumidityMin+2){
            HumidityMax--;
            EEPROM.write(8,HumidityMax);
            Screen14UpdateHMax();
            }
       break;    
       case 15:
          if(MachineStatus == 0 && HumidityControl==1){digitalWrite(DO_Humidity,LOW);}
          if(MachineStatus == 0 && HumidityControl==2){digitalWrite(DO_Humidity,HIGH);}
          PrintOutputStatus();       
       break;                 
       case 16:
          if(HCalibPressed==true && Val_HumCalib>=1){     
             Val_HumCalib--;
             EEPROM.write(11,Val_HumCalib);
             Screen16UpdateHCalib();           
          }
          if(HDirectPressed==true && Val_HumDirect>=1){
            Val_HumDirect--;
            EEPROM.write(10,Val_HumDirect);
            Screen16UpdateHDirect();
         }        
       break;
       case 18:
          if(HumidityControl>1){
            HumidityControl--;
            EEPROM.write(12,HumidityControl);
            Screen18Update();
          }
       break;
       case 19:
          GraphTempValuesReset();      
          GraphHumValuesReset();      
       break;
       case 20:
          AuxHourScreen20=AuxHourScreen20-1;
          if(AuxHourScreen20<=-1){AuxHourScreen20=23;}
          CurrentScreen=20;
          Screen20();
       break;
       case 22:
          if(EventsRegInterval==0){EventsRegInterval=60;}
         // else if(EventsRegInterval==3){EventsRegInterval=0;}
          else if(EventsRegInterval==5){EventsRegInterval=0;}                                        
          else if(EventsRegInterval==10){EventsRegInterval=5;}          
          else if(EventsRegInterval==15){EventsRegInterval=10;}
          else if(EventsRegInterval==20){EventsRegInterval=15;}
          else if(EventsRegInterval==30){EventsRegInterval=20;}
          else if(EventsRegInterval==60){EventsRegInterval=30;}
          else{EventsRegInterval=0;}
          EEPROM.write(15,EventsRegInterval);
          Screen22Update();
       break;
       case 25:
          if(MachineStatus == 0 && RL3OutputControl==1){digitalWrite(DO_RL3,LOW);}
          if(MachineStatus == 0 && RL3OutputControl==2){digitalWrite(DO_RL3,HIGH);}
          PrintOutputStatus();       
       break;
       case 26:
          if(MachineStatus == 0 && RL4OutputControl==1){digitalWrite(DO_RL4,LOW);}
          if(MachineStatus == 0 && RL4OutputControl==2){digitalWrite(DO_RL4,HIGH);}
          PrintOutputStatus();       
       break;
       case 27:
          if(DisplayOutputsScreen1==1){
            DisplayOutputsScreen1=0;
            EEPROM.write(18,DisplayOutputsScreen1);
          }
          else{
            DisplayOutputsScreen1=0;
            EEPROM.write(18,DisplayOutputsScreen1);
          }
          Screen27Update();
       break;
       case 28:
          if(RL3OutputControl>1){
            RL3OutputControl--;
            EEPROM.write(16,RL3OutputControl);
            Screen28Update();
          }
       break;
       case 29:
          if(RL4OutputControl>1){
            RL4OutputControl--;
            EEPROM.write(17,RL4OutputControl);
            Screen29Update();
          }
       break;
       case 31:
            if(RL3HourOnPressed == true){
              if(RL3ConfigHourOn>0){RL3ConfigHourOn--;}else{RL3ConfigHourOn=23;}
              EEPROM.write(35,RL3ConfigHourOn);
              Screen31UpdateHourOn();
            }
            else if(RL3MinuteOnPressed == true){
              if(RL3ConfigMinuteOn>0){RL3ConfigMinuteOn--;}else{RL3ConfigMinuteOn=59;}
              EEPROM.write(36,RL3ConfigMinuteOn);
              Screen31UpdateMinuteOn();              
            }            
            else if(RL3HourOffPressed == true){
              if(RL3ConfigHourOff>0){RL3ConfigHourOff--;}else{RL3ConfigHourOff=23;}
              EEPROM.write(37,RL3ConfigHourOff);
              Screen31UpdateHourOff();              
            }
            else if(RL3MinuteOffPressed == true){
              if(RL3ConfigMinuteOff>0){RL3ConfigMinuteOff--;}else{RL3ConfigMinuteOff=59;}
              EEPROM.write(38,RL3ConfigMinuteOff);
              Screen31UpdateMinuteOff();               
            }                   
       break;
       case 33:
            if(RL4HourOnPressed == true){
              if(RL4ConfigHourOn>0){RL4ConfigHourOn--;}else{RL4ConfigHourOn=23;}
              EEPROM.write(39,RL4ConfigHourOn);
              Screen33UpdateHourOn();
            }
            else if(RL4MinuteOnPressed == true){
              if(RL4ConfigMinuteOn>0){RL4ConfigMinuteOn--;}else{RL4ConfigMinuteOn=59;}
              EEPROM.write(40,RL4ConfigMinuteOn);
              Screen33UpdateMinuteOn();              
            }            
            else if(RL4HourOffPressed == true){
              if(RL4ConfigHourOff>0){RL4ConfigHourOff--;}else{RL4ConfigHourOff=23;}
              EEPROM.write(41,RL4ConfigHourOff);
              Screen33UpdateHourOff();              
            }
            else if(RL4MinuteOffPressed == true){
              if(RL4ConfigMinuteOff>0){RL4ConfigMinuteOff--;}else{RL4ConfigMinuteOff=59;}
              EEPROM.write(42,RL4ConfigMinuteOff);
              Screen33UpdateMinuteOff();               
            }                   
       break;
       case 34:
            if(ScreenSaverTimeout >0){
              ScreenSaverTimeout = ScreenSaverTimeout-5;
              EEPROM.write(43,ScreenSaverTimeout);
              Screen34Update();
              ScreenSaverTimeoutCnt=0;            
          }
       break;                                                                                 
      }          
     ButtonDown=false;               
  }  
}

  void Screen0(){
    
    PrintScreenLayout2();
    tft.setTextSize(2);

    //Modelo
    tft.setTextColor(YELLOW);
    tft.setCursor(10,13);
    tft.print("Modelo:");
    tft.setTextColor(WHITE);
    tft.setCursor(95,13);
    tft.print(DeviceModel); 
    tft.drawLine(5,40,315,40,WHITE);
    tft.drawLine(5,41,315,41,WHITE);

    //Numero Serie
    tft.setTextColor(YELLOW);
    tft.setCursor(10,53);
    tft.print("Numero Serie:");
    tft.setTextColor(WHITE);
    tft.setCursor(170,53);
    tft.print(DeviceSN);
    tft.drawLine(5,80,315,80,WHITE);
    tft.drawLine(5,81,315,81,WHITE);

    //Mes de Fabríco
    tft.setTextColor(YELLOW);    
    tft.setCursor(10,93);
    tft.print("Mes Fabricado:");
    tft.setTextColor(WHITE);    
    tft.setCursor(179,93);
    tft.print(devicemonth[DeviceMonth -1]);
    tft.drawLine(5,120,315,120,WHITE);
    tft.drawLine(5,121,315,121,WHITE);

    //Ano de Fabríco
    tft.setTextColor(YELLOW);       
    tft.setCursor(10,133);
    tft.print("Ano Fabricado:");
    tft.setTextColor(WHITE);
    tft.setCursor(179,133);
    tft.print(DeviceYear); 
    tft.drawLine(5,160,315,160,WHITE);
    tft.drawLine(5,161,315,161,WHITE);

    //Desonvolvido Por
    tft.setTextColor(YELLOW); 
    tft.setCursor(10,173);
    tft.print("CopyRight  :");
    tft.drawCircle(128,175,9,YELLOW);
    tft.setCursor(124,167);
    tft.print("c");
    tft.setTextColor(WHITE);
    tft.setCursor(163,173);
    tft.print(DeviceDeveloper);
  
  }

  void Screen1(){
    
    PrintScreenLayout2();
    PrintTempHum();
    PrintMachineStatus();
    PrintDateTime();  
    PrintOutputStatus();
    
  if(SDCardOk==true){  
    bmpDraw("Water.bmp",6,3);
    bmpDraw("Water.bmp",268,3);
  }      
 }

  void Screen2(){
    PrintScreenLayout3();
    PrintTempHum();       
  }

  void Screen3(){

    PrintScreenLayout1();
      
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.setCursor(82,11);
    tft.print("Grafico Temperatura");

// Desenhar linha para Y Temperatura
    tft.drawLine(30,28,30,165,RED);
    tft.drawLine(31,28,31,165,RED);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(12,15);
    tft.print("Temp(  )");
    tft.setCursor(42,12);
    tft.print("o");
    tft.setCursor(48,15);
    tft.print("C");

// Desenhar Linha para X Tempo (H)    
    tft.drawLine(30,165,312,165,RED);
    tft.drawLine(30,164,312,164,RED);

    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(273,183);
    tft.print("(Horas)");

// Desenhar Linhas em Y para dividir temperatura em escalas de 10ºC (Pixel 35 = 130ºC && Pixel 165 = 0ºC )

    for (int i=35; i <= 160; i=i+10){
      tft.drawLine(28,i,31,i,WHITE);
   }

   for (int i=40; i <= 160; i=i+10){
      tft.drawLine(30,i,31,i,WHITE);
   }
   
   for (int i=35; i <= 160; i=i+10){
      tft.drawLine(32,i,314,i,DARKGREY);
   }

// Imprimir Valores para eixo Y (Temperatura)

   int Aux= 142;
   tft.setTextColor(WHITE);
   tft.setTextSize(1); 

   for (int a=20; a<=120; a=a+20){
      if(a<=90){tft.setCursor(14,Aux);} else {tft.setCursor(8,Aux);}   
      tft.print(a);
      Aux = Aux + -20;
   }
   
    tft.setCursor(20,162);
    tft.print("0");

// Desenhar Linhas em X para dividir tempo em escalas de 0h até as 23h (Pixel 30-> 00:00 Pixel 33 -> 00:15 Pixel de 3 em 3 Pixel 306 23:00 -> Pixel 315: 23:45)

    for (int i=42; i <= 312; i=i+12){
       tft.drawLine(i,165,i,168,WHITE);
   } 
   
    for (int i=42; i <= 312; i=i+12){
      tft.drawLine(i,163,i,35,DARKGREY);
   } 
   

// Imprimir Valores para eixo X (Tempo)

    int Aux1= 40;
    tft.setTextColor(WHITE);
    tft.setTextSize(1);

    for (int a=1; a<=23; a++){
      if(a<=9){tft.setCursor(Aux1,171);} else {tft.setCursor(Aux1-3,171);}   
       if(a & 0x01){tft.print(a);}
       Aux1 = Aux1 + 12;
    }

// Imprimir Linhas para Temperatura Maxima e Minima
 
    if(Graph_TMax_TMin==1){
  
       tft.drawLine(32,165-TemperatureMax,314,165-TemperatureMax,CYAN);
       tft.drawLine(32,165-TemperatureMin,314,165-TemperatureMin,CYAN);
    
       tft.setTextColor(CYAN);
       tft.setTextSize(1);
       tft.setCursor(32,183);
       tft.print("TempMax/");
       tft.setTextColor(CYAN);
       tft.setTextSize(1);
       tft.setCursor(80,183);
       tft.print("TempMin(  )");
       tft.setCursor(128,181);
       tft.print("o");
       tft.setCursor(134,183);
       tft.print("C"); 
    }

// ************ Desenhar Gráfico de Temperatura
      DrawTemperatureGraph();
 }

void DrawTemperatureGraph(){
// ************ Desenhar Gráfico de Temperatura
      int Aux2= 30;
      int Aux3;           
      tft.setTextColor(YELLOW); 
      EEPROM.write(99,EEPROM.read(100));
      
         for (int a=100; a<=195; a++){          
            Aux3=EEPROM.read(a);            
              if(Aux3>0 && Aux3<=130){
                tft.drawLine(Aux2,165-EEPROM.read(a-1),Aux2+3,165-EEPROM.read(a),YELLOW);
                tft.drawLine(Aux2,164-EEPROM.read(a-1),Aux2+3,164-EEPROM.read(a),YELLOW);
              }        
            Aux2 = Aux2 + 3;
       }   
}

 void Screen3GraphRefresh(){
// ************ Atualizar Gráfico de Temperatura    
      int Aux1;
      int Aux2;
      Aux2=GraphPointer-100;               
      Aux1 = Aux2*3+30;
      EEPROM.write(99,EEPROM.read(100)); 
                        
      if(EEPROM.read(GraphPointer)>0 && EEPROM.read(GraphPointer)<=130){
         TSPoint p = ts.getPoint();
         pinMode(XM, OUTPUT);
         pinMode(YP, OUTPUT);             
         tft.drawLine(Aux1,165-EEPROM.read(GraphPointer-1),Aux1+3,165-EEPROM.read(GraphPointer),YELLOW);             
         tft.drawLine(Aux1,164-EEPROM.read(GraphPointer-1),Aux1+3,164-EEPROM.read(GraphPointer),YELLOW);
     }           
 }

  void Screen4(){
   
    PrintScreenLayout4();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.drawLine(5,85,315,85,WHITE);
    tft.drawLine(5,86,315,86,WHITE); 

    tft.setCursor(12,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Automatico"); 

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

 //Escrever Temperatura Maxima   
    tft.setCursor(15,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Temperatura");        
    tft.setCursor(46,65);
    tft.setTextSize(2);
    tft.print("Maxima"); 

 //Escrever Temperatura Minima
    tft.setCursor(169,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Temperatura");        
    tft.setCursor(200,65);
    tft.setTextSize(2);
    tft.print("Minima");
    
 //Escrever Valor Temperatura Maxima   
    if(TemperatureMax<100){tft.setCursor(45,125);}
    if(TemperatureMax>=100){tft.setCursor(20,125);}
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print(TemperatureMax);
    tft.setCursor(100,120);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("o");   
    tft.setCursor(113,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("C");
    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor Temperatura Minima   
    if(TemperatureMin<100){tft.setCursor(200,125);}
    if(TemperatureMin>=100){tft.setCursor(175,125);}
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print(TemperatureMin);
    tft.setCursor(254,120);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("o");   
    tft.setCursor(266,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("C");
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");

 }

 void Screen4UpdateTMax(){
 //Escrever Valor Temperatura Maxima
    tft.fillRect(8,105,89,65,BLACK);    
    if(TemperatureMax<100){tft.setCursor(45,125);}
    if(TemperatureMax>=100){tft.setCursor(20,125);}
    if(TMaxPressed==true){tft.setTextColor(YELLOW);}
    if(TMaxPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.fillRect(8,105,89,65,BLACK);
    tft.print(TemperatureMax);  
 }

 void Screen4UpdateTMin(){   
//Escrever Valor Temperatura Minima 
    tft.fillRect(162,105,90,65,BLACK);
    if(TemperatureMin<100){tft.setCursor(200,125);}
    if(TemperatureMin>=100){tft.setCursor(175,125);}
    if(TMinPressed==true){tft.setTextColor(YELLOW);}
    if(TMinPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(TemperatureMin); 
 }

  void Screen5(){
    PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.drawLine(5,95,315,95,WHITE);
    tft.drawLine(5,96,315,96,WHITE); 
    tft.drawLine(158,96,158,36,WHITE);
    tft.drawLine(159,96,159,36,WHITE);

    tft.setCursor(36,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Manual");

    tft.drawLine(158,96,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,96,159,192,WHITE);

    tft.setCursor(15,60);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Temperatura");

    PrintTempHum();

    tft.setCursor(120,131);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("o");     
    tft.setCursor(135,134);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("C");
   
     tft.setTextColor(WHITE);
     tft.setTextSize(2);
     tft.setCursor(178,47);
     tft.print("Saida: RL1");
     tft.setCursor(193,72);
     tft.print("Valvula");
      
  // Estado do Output da Valvula
      tft.setTextColor(WHITE);
      tft.setTextSize(1);
      tft.fillCircle(175,185,3,GREEN);
      tft.setCursor(185,182);
      tft.print("Aqc.Casa");
      tft.fillCircle(248,185,3,RED);
      tft.setCursor(258,182);
      tft.print("Aqc.Agua");
      
      PrintOutputStatus(); 
  }

  void Screen6(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(43,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Calibrar Temperatura");

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

//Escrever Temperatura Directa  
    tft.setCursor(33,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Valor do");        
    tft.setCursor(44,65);
    tft.setTextSize(2);
    tft.print("Sensor"); 

//Escrever Temperatura Calibrada
    tft.setCursor(208,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Valor");        
    tft.setCursor(185,65);
    tft.setTextSize(2);
    tft.print("Calibrado");
    
    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE); 
    
//Escrever Valor Temperatura Directa
    Screen6UpdateTDirect();
    tft.setCursor(120,120);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("o");   
    tft.setCursor(133,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("C");
    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor Temperatura Calibrada 
    Screen6UpdateTCalib();
    tft.setCursor(274,120);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("o");   
    tft.setCursor(286,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("C");
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");
  }

 void Screen6UpdateTDirect(){
 //Escrever Valor Temperatura Directa
    tft.fillRect(8,105,105,65,BLACK);    
    if(Val_TempDirect<10){tft.setCursor(25,125);}else if(Val_TempDirect <100){tft.setCursor(15,125);}else{tft.setCursor(25,125);}
    if(TDirectPressed==true){tft.setTextColor(YELLOW);}
    if(TDirectPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(Val_TempDirect);
    tft.print(".");
    tft.print(Val_TempDirectAux); 
 }

 void Screen6UpdateTCalib(){  
//Escrever Valor Temperatura Calibrada 
    tft.fillRect(162,105,105,65,BLACK);
    if(Val_TempCalib<10){tft.setCursor(180,125);}else if(Val_TempCalib<100){tft.setCursor(170,125);}else{tft.setCursor(180,125);}
    if(TCalibPressed==true){tft.setTextColor(YELLOW);}
    if(TCalibPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(Val_TempCalib);
    tft.print(".");
    tft.print(Val_TempCalibAux); 
 }

  void Screen7(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(55,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Configurar Sensor");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

 //Escrever Temperatura Directa  
    tft.setCursor(35,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Intervalo de Leitura");        

 //Escrever Valor Temperatura Directa
    Screen7UpdateTempInterval();
    tft.setCursor(170,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("Seg");

    tft.setCursor(50,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Valor Minimo:1s      Valor Maximo:30s");
    tft.setTextColor(WHITE);             
  }

  void Screen7UpdateTempInterval(){
    tft.fillRect(50,110,118,50,BLACK);
    if(TempHumReadInterval/1000 <10){tft.setCursor(125,125);}
    if(TempHumReadInterval/1000 >=10){tft.setCursor(115,125);}
    tft.setTextSize(4);
    tft.print(TempHumReadInterval/1000);    
  }

  void Screen8(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(33,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Relogio: Acertar Data");

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

 //Escrever Dia da Semana  
    tft.setCursor(15,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Semana: Dia");        
 
 //Escrever Mês : Dia
    tft.setCursor(190,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Mes: Dia");        

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);    

 //Escrever Valor do dia da semana 
    Screen8UpdateDayOfWeek();
    
//Escrever Valor do dia do Mês 
    Screen8UpdateDay();
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");
  }

 void Screen8UpdateDayOfWeek(){
//Escrever Valor Dia da Semana
    tft.fillRect(15,105,130,65,BLACK);  
    tft.setCursor(45,125);   
    if(DayOfWeekPressed==true){tft.setTextColor(YELLOW);}
    if(DayOfWeekPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(DaysOfTheWeek);  
 }

 void Screen8UpdateDay(){  
//Escrever Valor Diado Mês 
    tft.fillRect(170,105,130,65,BLACK);
    tft.setCursor(215,125);
    if(DayPressed==true){tft.setTextColor(YELLOW);}
    if(DayPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    if(Day<10){tft.print("0");
    tft.print(Day);}
    if(Day>=10){tft.print(Day);} 
 }

  void Screen9(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(33,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Relogio: Acertar Data");

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

//Escrever MÊs 
    tft.setCursor(65,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Mes");        
 
 //Escrever Ano
    tft.setCursor(220,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Ano");        

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE); 
    
 //Escrever Valor do Mês
    Screen9UpdateMonth();
    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor do Ano
    Screen9UpdateYear();
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");
  }

 void Screen9UpdateMonth(){
//Escrever Valor Dia da Semana
    tft.fillRect(15,105,130,65,BLACK); 
    tft.setCursor(60,125);   
    if(MonthPressed==true){tft.setTextColor(YELLOW);}
    if(MonthPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    if(Month<10){tft.print("0");
    tft.print(Month);}
    if(Month>=10){tft.print(Month);}
 }

 void Screen9UpdateYear(){  
//Escrever Valor Diado Mês 
    tft.fillRect(170,105,130,65,BLACK);
    tft.setCursor(190,125); 
    if(YearPressed==true){tft.setTextColor(YELLOW);}
    if(YearPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(Year);
 }

  void Screen10(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(33,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Relogio: Acertar Tempo");

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

//Escrever Hora
    tft.setCursor(58,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Hora");        
 

 //Escrever Minuto
    tft.setCursor(197,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Minutos");        

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE); 
    
//Escrever Valor da Hora
    tft.setCursor(60,125);   
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    if(Hour<10){tft.print("0");
    tft.print(Hour);}
    if(Hour>=10){tft.print(Hour);}

    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor do Minuto
    tft.setCursor(215,125); 
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    if(Minute<10){tft.print("0");
    tft.print(Minute);}
    if(Minute>=10){tft.print(Minute);}

    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");
  }

 void Screen10UpdateHour(){
 //Escrever Valor Dia da Semana
    tft.fillRect(15,105,130,65,BLACK);
    tft.setCursor(60,125);   
    if(HourPressed==true){tft.setTextColor(YELLOW);}
    if(HourPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    if(Hour<10){tft.print("0");
    tft.print(Hour);}
    if(Hour>=10){tft.print(Hour);}
 }

 void Screen10UpdateMinute(){  
//Escrever Valor Diado Mês 
    tft.fillRect(170,105,130,65,BLACK);
    tft.setCursor(215,125); 
    if(MinutePressed==true){tft.setTextColor(YELLOW);}
    if(MinutePressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    if(Minute<10){tft.print("0");
    tft.print(Minute);}
    if(Minute>=10){tft.print(Minute);}
 }

  void Screen11(){
      
   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(43,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Controlo da Valvula");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

 //Escrever Temperatura Directa  
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(35,42);
    tft.print("Modo de Funcionamento");
    tft.setCursor(20,65);
    tft.print("do Contacto da Saida RL1");        

    Screen11Update();

    tft.setCursor(45,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Saida para Controlo da Temperatura: RL1");
   
  }

  void Screen11Update(){
    
    tft.fillRect(40,110,250,60,BLACK);
    tft.setTextColor(WHITE); 
    tft.setTextSize(4);
    
    if(TemperatureControl==2){
      tft.setCursor(92,125);
      tft.print("Normal");         
    }
    else if (TemperatureControl==1){
      tft.setCursor(52,125);
      tft.print("Invertido");
    } 
  }

  void Screen12(){
      PrintScreenLayout3();
      PrintTempHum();      
  }

  void Screen13(){

    PrintScreenLayout1();
      
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.setCursor(87,11);
    tft.print("Grafico Humidade");

// Desenhar linha para Y Humidade
    tft.drawLine(30,28,30,165,RED);
    tft.drawLine(31,28,31,165,RED);

    tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(15,15);
    tft.print("(%RH)");

// Desenhar Linha para X Tempo (H)    
    tft.drawLine(30,165,312,165,RED);
    tft.drawLine(30,164,312,164,RED);

    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(273,183);
    tft.print("(Horas)");   

// Desenhar Linhas em Y para dividir Humidade em escalas de 10%rh (Pixel 35 = 130%rh && Pixel 165 = 0%rh )

    for (int i=35; i <= 160; i=i+10){
      tft.drawLine(28,i,31,i,WHITE);
   }
   
   for (int i=40; i <= 160; i=i+10){
      tft.drawLine(30,i,31,i,WHITE);
   }
   
   for (int i=35; i <= 160; i=i+10){
      tft.drawLine(32,i,314,i,DARKGREY);
   }

// Imprimir Valores para eixo Y (Humidade)

   int Aux= 142;
   tft.setTextColor(WHITE);
   tft.setTextSize(1); 

   for (int a=20; a<=120; a=a+20){
      if(a<=90){tft.setCursor(14,Aux);} else {tft.setCursor(8,Aux);}   
      tft.print(a);
      Aux = Aux + -20;
   }
   
    tft.setCursor(20,162);
    tft.print("0");

// Desenhar Linhas em X para dividir tempo em escalas de 0h até as 23h (Pixel 30-> 00:00 Pixel 33 -> 00:15 Pixel de 3 em 3 Pixel 306 23:00 -> Pixel 315: 23:45)

    for (int i=42; i <= 312; i=i+12){
      tft.drawLine(i,165,i,168,WHITE);
   } 

    for (int i=42; i <= 312; i=i+12){
      tft.drawLine(i,163,i,35,DARKGREY);
   } 
   
// Imprimir Valores para eixo X (Tempo)

    int Aux1= 40;
    tft.setTextColor(WHITE);
    tft.setTextSize(1);

    for (int a=1; a<=23; a++){
      if(a<=9){tft.setCursor(Aux1,171);} else {tft.setCursor(Aux1-3,171);}   
        if(a & 0x01){tft.print(a);}
        Aux1 = Aux1 + 12;
    }

 // Imprimir Linhas para Humidade Maxima e Minima
 
    if(Graph_HMax_HMin==1){
  
       tft.drawLine(32,165-HumidityMax,314,165-HumidityMax,CYAN);
       tft.drawLine(32,165-HumidityMin,314,165-HumidityMin,CYAN);
        
        tft.setTextColor(CYAN);
        tft.setTextSize(1);
        tft.setCursor(32,183);
        tft.print("HumMin/HumMax(%rh)");
    }

// ************ Desenhar Gráfico de Humidade
      DrawHumidityGraph();
 }

void DrawHumidityGraph(){
// ************ Desenhar Gráfico de Humidade
     int Aux2= 30;
      int Aux3;           
      tft.setTextColor(BLUE); 
      EEPROM.write(199,EEPROM.read(200));
      
         for (int a=200; a<=295; a++){         
            Aux3=EEPROM.read(a);            
              if(Aux3>0 && Aux3<=130){
                if(CurrentScreen==13){
                  tft.drawLine(Aux2,165-EEPROM.read(a-1),Aux2+3,165-EEPROM.read(a),BLUE);
                  tft.drawLine(Aux2,164-EEPROM.read(a-1),Aux2+3,164-EEPROM.read(a),BLUE);
                }
                else if (CurrentScreen==19){
                  tft.drawLine(Aux2,165-EEPROM.read(a-1),Aux2+3,165-EEPROM.read(a),BLUE);
                  tft.drawLine(Aux2,164-EEPROM.read(a-1),Aux2+3,164-EEPROM.read(a),BLUE);                
                }
              }       
            Aux2 = Aux2 + 3;
       }
}


 void Screen13GraphRefresh(){
// ************ Atualizar Gráfico de Temperatura    
      int Aux1;
      int Aux2;
      Aux2=GraphPointer1-200;               
      Aux1 = Aux2*3+30;
      EEPROM.write(199,EEPROM.read(200)); 
                        
      if(EEPROM.read(GraphPointer1)>0 && EEPROM.read(GraphPointer1)<=130){
         TSPoint p = ts.getPoint();
         pinMode(XM, OUTPUT);
         pinMode(YP, OUTPUT); 
        if(CurrentScreen==13){             
           tft.drawLine(Aux1,165-EEPROM.read(GraphPointer1-1),Aux1+3,165-EEPROM.read(GraphPointer1),YELLOW);             
           tft.drawLine(Aux1,164-EEPROM.read(GraphPointer1-1),Aux1+3,164-EEPROM.read(GraphPointer1),YELLOW);
        }
        else if (CurrentScreen==19){
           tft.drawLine(Aux1,165-EEPROM.read(GraphPointer1-1),Aux1+3,165-EEPROM.read(GraphPointer1),BLUE);             
           tft.drawLine(Aux1,164-EEPROM.read(GraphPointer1-1),Aux1+3,164-EEPROM.read(GraphPointer1),BLUE);         
        }
     }           
 }
 
  void Screen14(){
   
    PrintScreenLayout4();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.drawLine(5,85,315,85,WHITE);
    tft.drawLine(5,86,315,86,WHITE); 

    tft.setCursor(12,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Automatico"); 

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

 //Escrever Humidade Maxima   
    tft.setCursor(33,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Humidade");        
    tft.setCursor(46,65);
    tft.setTextSize(2);
    tft.print("Maxima"); 

 //Escrever Humidade Minima
    tft.setCursor(187,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Humidade");        
    tft.setCursor(200,65);
    tft.setTextSize(2);
    tft.print("Minima");
    

 //Escrever Valor Humidade Maxima   
    if(HumidityMax<100){tft.setCursor(45,125);}
    if(HumidityMax>=100){tft.setCursor(20,125);}
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print(HumidityMax);   
    tft.setCursor(108,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("%RH");
    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor Humidade Minima   
    if(HumidityMin<100){tft.setCursor(200,125);}
    if(HumidityMin>=100){tft.setCursor(175,125);}
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print(HumidityMin);   
    tft.setCursor(261,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("%RH");
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");

 }

 void Screen14UpdateHMax(){

 //Escrever Valor Humidade Maxima

    tft.fillRect(8,105,89,65,BLACK);    
    if(HumidityMax<100){tft.setCursor(45,125);}
    if(HumidityMax>=100){tft.setCursor(20,125);}
    if(HMaxPressed==true){tft.setTextColor(YELLOW);}
    if(HMaxPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.fillRect(8,105,89,65,BLACK);
    tft.print(HumidityMax); 
 }

 void Screen14UpdateHMin(){   
//Escrever Valor Humidade Minima 
    tft.fillRect(162,105,90,65,BLACK);
    if(HumidityMin<100){tft.setCursor(200,125);}
    if(HumidityMin>=100){tft.setCursor(175,125);}
    if(HMinPressed==true){tft.setTextColor(YELLOW);}
    if(HMinPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(HumidityMin); 
 }

  void Screen15(){

    PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.drawLine(5,95,315,95,WHITE);
    tft.drawLine(5,96,315,96,WHITE); 
    tft.drawLine(158,96,158,36,WHITE);
    tft.drawLine(159,96,159,36,WHITE);

    tft.setCursor(36,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Manual");

    tft.drawLine(158,96,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,96,159,192,WHITE);

     tft.setCursor(35,60);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Humidade");
    
    PrintTempHum();

    tft.setCursor(119,141);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("%RH");     

    
     tft.setTextColor(WHITE);
     tft.setTextSize(2);
     tft.setCursor(178,60);
     tft.print("Saida: RL2");
  
// Estado do Output RL2
      tft.setTextColor(WHITE);
      tft.setTextSize(1);
      tft.fillCircle(175,185,3,GREEN);
      tft.setCursor(185,182);
      tft.print("Ligado");
      tft.fillCircle(248,185,3,RED);
      tft.setCursor(258,182);
      tft.print("Desligado");
      
      PrintOutputStatus();   
  }

  void Screen16(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(57,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Calibrar Humidade");

    tft.drawLine(158,36,158,192,WHITE); // Linha a dividir 
    tft.drawLine(159,36,159,192,WHITE);

 //Escrever Humidade Directa  
    tft.setCursor(33,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Valor do");        
    tft.setCursor(44,65);
    tft.setTextSize(2);
    tft.print("Sensor"); 

 //Escrever Humidade Calibrada
    tft.setCursor(208,44);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Valor");        
    tft.setCursor(185,65);
    tft.setTextSize(2);
    tft.print("Calibrado");
    
    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE); 
    
//Escrever Valor Humidade Directa
    Screen16UpdateHDirect();
    tft.setCursor(108,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("%RH");
    tft.setCursor(16,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");          
    
//Escrever Valor Humidade Calibrada 
    Screen16UpdateHCalib();
    tft.setCursor(261,130);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("%RH");
    tft.setCursor(172,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Pressionar para Editar");
  }

 void Screen16UpdateHDirect(){

 //Escrever Valor Humidade Directa
    tft.fillRect(8,105,89,65,BLACK);    
    if(Val_HumDirect<10){tft.setCursor(55,125);}else if(Val_HumDirect <100){tft.setCursor(45,125);}else{tft.setCursor(25,125);}
    if(HDirectPressed==true){tft.setTextColor(YELLOW);}
    if(HDirectPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.fillRect(8,105,89,65,BLACK);
    tft.print(Val_HumDirect); 
 }

 void Screen16UpdateHCalib(){
   
//Escrever Valor Humidade Calibrada 
    tft.fillRect(162,105,90,65,BLACK);
    if(Val_HumCalib<10){tft.setCursor(210,125);}else if(Val_HumCalib<100){tft.setCursor(200,125);}else{tft.setCursor(180,125);}
    if(HCalibPressed==true){tft.setTextColor(YELLOW);}
    if(HCalibPressed==false){tft.setTextColor(WHITE);}
    tft.setTextSize(4);
    tft.print(Val_HumCalib);
 }

  void Screen17(){

    PrintScreenLayout1();
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);

    tft.setCursor(20,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Estado das Saidas");

    tft.drawLine(5,75,315,75,WHITE);
    tft.drawLine(5,76,315,76,WHITE); 

    tft.setCursor(85,48);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Estado Atual");

    tft.drawLine(5,105,315,105,WHITE);
    tft.drawLine(5,106,315,106,WHITE);
    tft.setCursor(15,84);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Saida:RL1 Valvula");

    tft.drawLine(5,135,315,135,WHITE);
    tft.drawLine(5,136,315,136,WHITE);
    tft.setCursor(15,114);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Saida:RL2 Reserva");

    tft.drawLine(5,165,315,165,WHITE);
    tft.drawLine(5,166,315,166,WHITE);
    tft.setCursor(15,144);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Saida:RL3 Programada");

    tft.setCursor(15,172);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Saida:RL4 Programada");
    
    tft.drawLine(260,75,260,193,WHITE);
    tft.drawLine(261,75,261,193,WHITE);
    
    PrintOutputStatus();
       
  }

  void Screen18(){
      
   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(37,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Controlo da Humidade");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

  
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(35,42);
    tft.print("Modo de Funcionamento");
    tft.setCursor(20,65);
    tft.print("do Contacto da Saida RL2");        

    Screen18Update();

    tft.setCursor(50,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Saida para Controlo da Humidade: RL2");  
  }

  void Screen18Update(){
    
    tft.fillRect(40,110,250,60,BLACK);
    tft.setTextColor(WHITE); 
    tft.setTextSize(4);
    
    if(HumidityControl==2){
      tft.setCursor(92,125);
      tft.print("Normal");         
    }
    else if (HumidityControl==1){
      tft.setCursor(52,125);
      tft.print("Invertido");
    } 
  }

 void Screen19(){

    PrintScreenLayout1();
      
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.setCursor(70,11);
    tft.print("Temperatura/Humidade");

// Desenhar linha para Y Temperatura
    tft.drawLine(30,28,30,165,RED);
    tft.drawLine(31,28,31,165,RED);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(12,19);
    tft.print("Temp(  )");
    tft.setCursor(42,16);
    tft.print("o");
    tft.setCursor(48,19);
    tft.print("C");

    tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(17,8);
    tft.print("(%RH)");

// Desenhar Linha para X Tempo (H)    
    tft.drawLine(30,165,312,165,RED);
    tft.drawLine(30,164,312,164,RED);

    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(273,183);
    tft.print("(Horas)");
    
// Desenhar Linhas em Y para dividir temperatura em escalas de 10ºC (Pixel 35 = 130ºC && Pixel 165 = 0ºC )

    for (int i=35; i <= 160; i=i+10){
      tft.drawLine(28,i,31,i,WHITE);
   }

   for (int i=40; i <= 160; i=i+10){
      tft.drawLine(30,i,31,i,WHITE);
   }
   
   for (int i=35; i <= 160; i=i+10){
      tft.drawLine(32,i,314,i,DARKGREY);
   }

// Imprimir Valores para eixo Y (Temperatura)

/*
   int Aux= 152;
   tft.setTextColor(WHITE);
   tft.setTextSize(1); 

   for (int a=10; a<=130; a=a+10){
      if(a<=90){tft.setCursor(14,Aux);} else {tft.setCursor(8,Aux);}   
      tft.print(a);
       Aux = Aux + -10;
       */
   int Aux= 142;
   tft.setTextColor(WHITE);
   tft.setTextSize(1); 

   for (int a=20; a<=120; a=a+20){
      if(a<=90){tft.setCursor(14,Aux);} else {tft.setCursor(8,Aux);}   
      tft.print(a);
       Aux = Aux + -20;
   }
   
    tft.setCursor(20,162);
    tft.print("0");

// Desenhar Linhas em X para dividir tempo em escalas de 0h até as 23h (Pixel 30-> 00:00 Pixel 33 -> 00:15 Pixel de 3 em 3 Pixel 306 23:00 -> Pixel 315: 23:45)

    for (int i=42; i <= 312; i=i+12){
      tft.drawLine(i,165,i,168,WHITE);
   } 

    for (int i=42; i <= 312; i=i+12){
      tft.drawLine(i,163,i,35,DARKGREY);
   }   

// Imprimir Valores para eixo X (Tempo)

    int Aux1= 40;
    tft.setTextColor(WHITE);
    tft.setTextSize(1);

    for (int a=1; a<=23; a++){
      if(a<=9){tft.setCursor(Aux1,171);} else {tft.setCursor(Aux1-3,171);}   
       if(a & 0x01){tft.print(a);}
       Aux1 = Aux1 + 12;
    }
    
// ************ Desenhar Gráfico de Temperatura e Humidade

      DrawTemperatureGraph();
      DrawHumidityGraph();
 }

 void Screen20(){

  int Aux1;
  //int Aux2;
  int Aux3;
  //int Aux4;

  Aux1 = 300 + AuxHourScreen20*4;
  //Aux2 = 400 + AuxHourScreen20*4;
  Aux3 = 500 + AuxHourScreen20*4;
 //Aux4 = 600 + AuxHourScreen20*4;  
  
    PrintScreenLayout();
  
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);

    tft.setCursor(65,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Registo de Dados");

    tft.drawLine(5,75,315,75,WHITE);
    tft.drawLine(5,76,315,76,WHITE); 

    tft.drawLine(100,75,100,193,WHITE); // Linha vertical a separar hora e temperatura
    tft.drawLine(101,75,101,193,WHITE);

    //tft.drawLine(200,75,200,193,WHITE); // Linha vertical a separar temperatura e Humidade
   //tft.drawLine(201,75,201,193,WHITE);

    tft.setCursor(55,48);
    tft.setTextColor(YELLOW);
    tft.setTextSize(2);
    if(Day<10){tft.print("0");
    tft.print(Day);}
    if(Day>=10){tft.print(Day);}
    tft.print("/");
    if(Month<10){tft.print("0");
    tft.print(Month);}
    if(Month>=10){tft.print(Month);}
    tft.print("/");
    tft.print(Year);
    tft.print(" as ");
    tft.print(AuxHourScreen20);
    tft.print("h");    

    tft.drawLine(5,105,315,105,WHITE);
    tft.drawLine(5,106,315,106,WHITE);
    tft.setCursor(25,84);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    if(AuxHourScreen20<=9){
      tft.print("0");
      tft.print(AuxHourScreen20);
      }
    else{tft.print(AuxHourScreen20);}  
    tft.print(":00       ");
    if(EEPROM.read(Aux1)!=0){
        tft.setTextColor(WHITE);
        tft.print(EEPROM.read(Aux1));
        tft.print(".");
        tft.print(EEPROM.read(Aux3));
        tft.setTextSize(1);    
        tft.print("  o");
        tft.setTextSize(2); 
        tft.print("C  "); 
    }
    /*if (EEPROM.read(Aux2)!=0){
        tft.print(EEPROM.read(Aux2));
        tft.print(".");
        tft.print(EEPROM.read(Aux4));      
        tft.print(" %rh");    
    }
   */
    tft.drawLine(5,135,315,135,WHITE);
    tft.drawLine(5,136,315,136,WHITE);
    tft.setCursor(25,114);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    if(AuxHourScreen20<=9){
      tft.print("0");
      tft.print(AuxHourScreen20);
      }
    else{tft.print(AuxHourScreen20);}
    tft.print(":15       ");
    if(EEPROM.read(Aux1+1)!=0){
        tft.setTextColor(WHITE);
        tft.print(EEPROM.read(Aux1+1));
        tft.print(".");
        tft.print(EEPROM.read(Aux3+1));       
        tft.setTextSize(1);    
        tft.print("  o");
        tft.setTextSize(2); 
        tft.print("C  ");
    }
    /*if(EEPROM.read(Aux2+1)!=0){
        tft.print(EEPROM.read(Aux2+1));
        tft.print(".");
        tft.print(EEPROM.read(Aux4+1));       
        tft.print(" %rh");
    }
    */
    tft.drawLine(5,165,315,165,WHITE);
    tft.drawLine(5,166,315,166,WHITE);
    tft.setCursor(25,144);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    if(AuxHourScreen20<=9){
      tft.print("0");
      tft.print(AuxHourScreen20);
      }
    else{tft.print(AuxHourScreen20);}
    tft.print(":30       ");
    if(EEPROM.read(Aux1+2)!=0){
        tft.setTextColor(WHITE);
        tft.print(EEPROM.read(Aux1+2));
        tft.print(".");
        tft.print(EEPROM.read(Aux3+2));      
        tft.setTextSize(1);    
        tft.print("  o");
        tft.setTextSize(2); 
        tft.print("C  ");
    }
    /*if(EEPROM.read(Aux2+2)!=0){
        tft.print(EEPROM.read(Aux2+2));
        tft.print(".");
        tft.print(EEPROM.read(Aux4+2));
        tft.print(" %rh");
    }
    */
    tft.setCursor(25,172);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    if(AuxHourScreen20<=9){
      tft.print("0");
      tft.print(AuxHourScreen20);
      }
    else{tft.print(AuxHourScreen20);}
    tft.print(":45       ");
    if(EEPROM.read(Aux1+3)!=0){
        tft.setTextColor(WHITE);
        tft.print(EEPROM.read(Aux1+3));
        tft.print(".");
        tft.print(EEPROM.read(Aux3+3));           
        tft.setTextSize(1);    
        tft.print("  o");
        tft.setTextSize(2); 
        tft.print("C  ");
    }
    /*if(EEPROM.read(Aux2+3)!=0){
        tft.print(EEPROM.read(Aux2+3));
        tft.print(".");
        tft.print(EEPROM.read(Aux4+3));      
        tft.print(" %rh");
    }
    */
 }

  void Screen21(){
    
  PrintScreenLayout3();

   // Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 
    
  if(TempHomePressed==true){
      tft.setCursor(60,12);
      tft.setTextColor(GREENYELLOW);
      tft.setTextSize(2);
      tft.print("Menu: Temperatura");
  }

  if(HumHomePressed==true){
      tft.setCursor(75,12);
      tft.setTextColor(GREENYELLOW);
      tft.setTextSize(2);
      tft.print("Menu: Humidade");
  }

    tft.fillRect(35,45,250,40,GREY);
    tft.drawRect(35,45,250,40,WHITE);
    tft.drawRect(34,46,250,38,WHITE);    
    tft.setCursor(110,57);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Graficos");

    tft.fillRect(35,95,250,40,GREY);
    tft.drawRect(35,95,250,40,WHITE);
    tft.drawRect(34,96,250,38,WHITE);    
    tft.setCursor(87,108);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Registo Dados");

    tft.fillRect(35,145,250,40,GREY);
    tft.drawRect(35,145,250,40,WHITE);
    tft.drawRect(34,146,250,38,WHITE);    
    tft.setCursor(53,157);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    if(TempHomePressed==true){tft.print("Temperatura (Zoom)");}else if(HumHomePressed==true){tft.print("  Humidade (Zoom)");}    
  }


void Screen22(){

   PrintScreenLayout4();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(53,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Registo de Eventos");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

 //Escrever Temperatura Directa  
    tft.setCursor(40,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Intervalo de Registo");        

 //Escrever Valor Temperatura Directa
    Screen22Update();             
  }

  void Screen22Update(){
    
    tft.fillRect(45,110,230,80,BLACK);
    tft.setTextColor(WHITE);
    
    if(EventsRegInterval==0){
        tft.setTextSize(3);
        tft.setCursor(80,125);
        tft.print("Desligado");
      }
    else if(EventsRegInterval<=5){
        tft.setTextSize(4);
        tft.setCursor(123,125);
        tft.print(EventsRegInterval);
        tft.setTextSize(3);
        tft.setCursor(165,130);
        tft.print("min");
      }
    else{
      tft.setTextSize(4);
      tft.setCursor(115,125);
      tft.print(EventsRegInterval);
      tft.setCursor(170,130);
      tft.setTextSize(3);
      tft.print("min");     
      } 
    
    tft.setCursor(110,175);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    if(EventsRegInterval==1){tft.print("60 Registos por hora");}
    if(EventsRegInterval==2){tft.print("30 Registos por hora");}
    if(EventsRegInterval==3){tft.print("20 Registos por hora");}
    if(EventsRegInterval==4){tft.print("15 Registos por hora");}
    if(EventsRegInterval==5){tft.print("12 Registos por hora");}
    if(EventsRegInterval==10){tft.print("6 Registos por hora");}
    if(EventsRegInterval==15){tft.print("4 Registos por hora");}
    if(EventsRegInterval==20){tft.print("3 Registos por hora");}
    if(EventsRegInterval==30){tft.print("2 Registos por hora");}
    if(EventsRegInterval==60){tft.print("1 Registo por hora");}
  }

void Screen23(){
    
    PrintScreenLayout1();

    // Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(75,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Config: Menu 1"); 

    tft.fillRect(35,45,250,40,GREY);
    tft.drawRect(35,45,250,40,WHITE);
    tft.drawRect(34,46,250,38,WHITE);    
    tft.setCursor(59,57);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Configurar Sensor");

    tft.fillRect(35,95,250,40,GREY);
    tft.drawRect(35,95,250,40,WHITE);
    tft.drawRect(34,96,250,38,WHITE);    
    tft.setCursor(65,108);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Inverter Saidas");

    tft.fillRect(35,145,250,40,GREY);
    tft.drawRect(35,145,250,40,WHITE);
    tft.drawRect(34,146,250,38,WHITE);    
    tft.setCursor(50,157);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Configurar Registos");
        
  }

  void Screen24(){
    
    PrintScreenLayout3();
    // Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(75,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Config: Menu 2"); 

    tft.fillRect(35,45,250,40,GREY);
    tft.drawRect(35,45,250,40,WHITE);
    tft.drawRect(34,46,250,38,WHITE);    
    tft.setCursor(48,57);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Programar Saida RL3");

    tft.fillRect(35,95,250,40,GREY);
    tft.drawRect(35,95,250,40,WHITE);
    tft.drawRect(34,96,250,38,WHITE);    
    tft.setCursor(48,108);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Programar Saida RL4");

    tft.fillRect(35,145,250,40,GREY);
    tft.drawRect(35,145,250,40,WHITE);
    tft.drawRect(34,146,250,38,WHITE);    
    tft.setCursor(76,157);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Ecras & Outros");  
  }

void Screen25(){

    PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 
    tft.setCursor(36,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Manual");
    
    tft.drawLine(5,90,315,90,WHITE);
    tft.drawLine(5,91,315,91,WHITE);   
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(68,53);
    tft.print("Saida: RL3");
  
// Estado do Output RL3
      tft.setTextColor(WHITE);
      tft.setTextSize(1);
      tft.fillCircle(175,185,3,GREEN);
      tft.setCursor(185,182);
      tft.print("Ligado");
      tft.fillCircle(248,185,3,RED);
      tft.setCursor(258,182);
      tft.print("Desligado");
      
      PrintOutputStatus();   
  }


void Screen26(){

    PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 
    tft.setCursor(36,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Menu: Controlo Manual");
    
    tft.drawLine(5,90,315,90,WHITE);
    tft.drawLine(5,91,315,91,WHITE);   
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(68,53);
    tft.print("Saida: RL4");
  
// Estado do Output RL4
      tft.setTextColor(WHITE);
      tft.setTextSize(1);
      tft.fillCircle(175,185,3,GREEN);
      tft.setCursor(185,182);
      tft.print("Ligado");
      tft.fillCircle(248,185,3,RED);
      tft.setCursor(258,182);
      tft.print("Desligado");
            
      PrintOutputStatus();   
  }  


  void Screen27(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(27,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Config. Ecra Principal");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

 //Escrever Temperatura Directa  
    tft.setCursor(18,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Mostrar Estado de Saidas");        

 //Escrever Valor Temperatura Directa
    Screen27Update();         
  }

  void Screen27Update(){
    tft.fillRect(15,110,290,81,BLACK);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(80,125);
    if(DisplayOutputsScreen1==0){
        tft.print("RL1 & RL2");
        tft.setCursor(68,180);
        tft.setTextColor(YELLOW);
        tft.setTextSize(1);
        tft.print("RL1:Temperatura / RL2: Reserva");
     }
    if(DisplayOutputsScreen1==1){
        tft.setTextColor(WHITE);
        tft.print("RL3 & RL4");
        tft.setCursor(110,180);
        tft.setTextColor(YELLOW);
        tft.setTextSize(1);
        tft.print("Saidas Programadas");          
    }
        
  }


   void Screen28(){
      
   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(32,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Controlo da Saida RL3");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

  
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(35,42);
    tft.print("Modo de Funcionamento");
    tft.setCursor(20,65);
    tft.print("do Contacto da Saida RL3");        

    Screen28Update();

    tft.setCursor(60,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Saida para Controlo Programado: RL3");  
  }

  void Screen28Update(){
    
    tft.fillRect(40,110,250,60,BLACK);
    tft.setTextColor(WHITE); 
    tft.setTextSize(4);
    
    if(RL3OutputControl==2){
      tft.setCursor(92,125);
      tft.print("Normal");         
    }
    else if (RL3OutputControl==1){
      tft.setCursor(52,125);
      tft.print("Invertido");
    } 
  }


  void Screen29(){
      
   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(32,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Controlo da Saida RL4");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

  
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(35,42);
    tft.print("Modo de Funcionamento");
    tft.setCursor(20,65);
    tft.print("do Contacto da Saida RL4");        

    Screen29Update();

    tft.setCursor(60,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Saida para Controlo Programado: RL4");  
  }

  void Screen29Update(){
    
    tft.fillRect(40,110,250,60,BLACK);
    tft.setTextColor(WHITE); 
    tft.setTextSize(4);
    
    if(RL4OutputControl==2){
      tft.setCursor(92,125);
      tft.print("Normal");         
    }
    else if (RL4OutputControl==1){
      tft.setCursor(52,125);
      tft.print("Invertido");
    } 
  }


 void Screen30(){

    PrintScreenLayout1();
    
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);
    tft.setCursor(25,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("RL3: Sel. Dia da Semana");

    tft.drawLine(159,36,159,193,WHITE); // Linha Vertical
    tft.drawLine(160,36,160,193,WHITE);


    tft.drawLine(5,75,315,75,WHITE);
    tft.drawLine(5,76,315,76,WHITE); 

    tft.drawLine(5,115,315,115,WHITE);
    tft.drawLine(5,116,315,116,WHITE); 

    tft.drawLine(5,155,315,155,WHITE);
    tft.drawLine(5,156,315,156,WHITE);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(95,200);
    tft.print("Selecionar para ativar");
    tft.setTextColor(WHITE);
    tft.fillCircle(103,223,3,GREEN);
    tft.setCursor(111,220);
    tft.print("Ativo |");
    tft.fillCircle(162,223,3,RED);
    tft.setCursor(170,220);
    tft.print("Desativo");

    Screen30Update(); 
       
  }

 void Screen30Update(){
    
   tft.setTextSize(2);

   if(RL3ConfigMon==0){tft.setTextColor(RED);} else if(RL3ConfigMon==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,50);
   tft.print("SEGUNDA");

   if(RL3ConfigTue==0){tft.setTextColor(RED);} else if(RL3ConfigTue==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,50);
   tft.print("TERCA");

   if(RL3ConfigWed==0){tft.setTextColor(RED);} else if(RL3ConfigWed==1){tft.setTextColor(GREEN);}  
   tft.setCursor(45,90);
   tft.print("QUARTA");

   if(RL3ConfigThu==0){tft.setTextColor(RED);} else if(RL3ConfigThu==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,90);
   tft.print("QUINTA");

   if(RL3ConfigFri==0){tft.setTextColor(RED);} else if(RL3ConfigFri==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,130);
   tft.print("SEXTA");

   if(RL3ConfigSat==0){tft.setTextColor(RED);} else if(RL3ConfigSat==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,130);
   tft.print("SABADO");

   if(RL3ConfigSun==0){tft.setTextColor(RED);} else if(RL3ConfigSun==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,170);
   tft.print("DOMINGO");

   if(RL3ConfigOff==0){tft.setTextColor(RED);} else if(RL3ConfigOff==1){tft.setTextColor(GREEN);}
   tft.setCursor(190,170);
   tft.print("DESLIGADO");
 }

 void Screen31(){
   
    PrintScreenLayout();

    tft.drawLine(158,36,158,192,WHITE); // Linha vertical a dividir 
    tft.drawLine(159,36,159,192,WHITE); 
     
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);
    tft.setCursor(42,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("RL3: Selecionar Hora");  


    tft.drawLine(5,65,315,65,WHITE);
    tft.drawLine(5,66,315,66,WHITE);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(53,45);   
    tft.print("LIGAR");
    tft.setCursor(188,45);   
    tft.print("DESLIGAR"); 
    
    tft.drawLine(5,125,315,125,WHITE);
    tft.drawLine(5,126,315,126,WHITE);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(16,184);    
    tft.print("Pressionar para Editar");          
     
    tft.setCursor(172,184);
    tft.print("Pressionar para Editar");

    tft.setCursor(16,116);
    tft.print("Pressionar para Editar");          
     
    tft.setCursor(172,116);
    tft.print("Pressionar para Editar");

    Screen31UpdateHourOn();
    Screen31UpdateMinuteOn();
    Screen31UpdateHourOff();
    Screen31UpdateMinuteOff();    

 }

 void Screen31UpdateHourOn(){
  
   tft.fillRect(10,70,145,42,BLACK);
   if(RL3HourOnPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(25,82);
   if(RL3ConfigHourOn < 10){tft.print("0"); tft.print(RL3ConfigHourOn);}else{tft.print(RL3ConfigHourOn);}
   tft.setTextSize(2);
   tft.setCursor(80,82);
   tft.print("Horas");

 }
 void Screen31UpdateMinuteOn(){

   tft.fillRect(10,130,145,50,BLACK);
   if(RL3MinuteOnPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(25,147);
   if(RL3ConfigMinuteOn < 10){tft.print("0"); tft.print(RL3ConfigMinuteOn);}else{tft.print(RL3ConfigMinuteOn);}
   tft.setTextSize(2);
   tft.setCursor(71,147);
   tft.print("Minutos");
 
 }
 void Screen31UpdateHourOff(){

   tft.fillRect(165,70,145,42,BLACK);
   if(RL3HourOffPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(179,82);
   if(RL3ConfigHourOff < 10){tft.print("0"); tft.print(RL3ConfigHourOff);}else{tft.print(RL3ConfigHourOff);}
   tft.setTextSize(2);
   tft.setCursor(234,82);
   tft.print("Horas");
 
 }
 void Screen31UpdateMinuteOff(){

   tft.fillRect(165,130,145,50,BLACK);
   if(RL3MinuteOffPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(179,147);
   if(RL3ConfigMinuteOff < 10){tft.print("0"); tft.print(RL3ConfigMinuteOff);}else{tft.print(RL3ConfigMinuteOff);}
   tft.setTextSize(2);
   tft.setCursor(225,147);
   tft.print("Minutos");
   
 }

void Screen32(){

    PrintScreenLayout1();
    
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);
    tft.setCursor(25,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("RL4: Sel. Dia da Semana");

    tft.drawLine(159,36,159,193,WHITE); // Linha Vertical
    tft.drawLine(160,36,160,193,WHITE);


    tft.drawLine(5,75,315,75,WHITE);
    tft.drawLine(5,76,315,76,WHITE); 

    tft.drawLine(5,115,315,115,WHITE);
    tft.drawLine(5,116,315,116,WHITE); 

    tft.drawLine(5,155,315,155,WHITE);
    tft.drawLine(5,156,315,156,WHITE);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(95,200);
    tft.print("Selecionar para ativar");
    tft.setTextColor(WHITE);
    tft.fillCircle(103,223,3,GREEN);
    tft.setCursor(111,220);
    tft.print("Ativo |");
    tft.fillCircle(162,223,3,RED);
    tft.setCursor(170,220);
    tft.print("Desativo");

    Screen32Update(); 
       
  }

 void Screen32Update(){
    
   tft.setTextSize(2);

   if(RL4ConfigMon==0){tft.setTextColor(RED);} else if(RL4ConfigMon==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,50);
   tft.print("SEGUNDA");

   if(RL4ConfigTue==0){tft.setTextColor(RED);} else if(RL4ConfigTue==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,50);
   tft.print("TERCA");

   if(RL4ConfigWed==0){tft.setTextColor(RED);} else if(RL4ConfigWed==1){tft.setTextColor(GREEN);}  
   tft.setCursor(45,90);
   tft.print("QUARTA");

   if(RL4ConfigThu==0){tft.setTextColor(RED);} else if(RL4ConfigThu==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,90);
   tft.print("QUINTA");

   if(RL4ConfigFri==0){tft.setTextColor(RED);} else if(RL4ConfigFri==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,130);
   tft.print("SEXTA");

   if(RL4ConfigSat==0){tft.setTextColor(RED);} else if(RL4ConfigSat==1){tft.setTextColor(GREEN);}
   tft.setCursor(200,130);
   tft.print("SABADO");

   if(RL4ConfigSun==0){tft.setTextColor(RED);} else if(RL4ConfigSun==1){tft.setTextColor(GREEN);}
   tft.setCursor(45,170);
   tft.print("DOMINGO");

   if(RL4ConfigOff==0){tft.setTextColor(RED);} else if(RL4ConfigOff==1){tft.setTextColor(GREEN);}
   tft.setCursor(190,170);
   tft.print("DESLIGADO");
 }


 void Screen33(){
   
    PrintScreenLayout();

    tft.drawLine(158,36,158,192,WHITE); // Linha vertical a dividir 
    tft.drawLine(159,36,159,192,WHITE); 
     
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE);
    tft.setCursor(42,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("RL4: Selecionar Hora");  


    tft.drawLine(5,65,315,65,WHITE);
    tft.drawLine(5,66,315,66,WHITE);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(53,45);   
    tft.print("LIGAR");
    tft.setCursor(188,45);   
    tft.print("DESLIGAR"); 
    
    tft.drawLine(5,125,315,125,WHITE);
    tft.drawLine(5,126,315,126,WHITE);

    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.setCursor(16,184);    
    tft.print("Pressionar para Editar");          
     
    tft.setCursor(172,184);
    tft.print("Pressionar para Editar");

    tft.setCursor(16,116);
    tft.print("Pressionar para Editar");          
     
    tft.setCursor(172,116);
    tft.print("Pressionar para Editar");

    Screen33UpdateHourOn();
    Screen33UpdateMinuteOn();
    Screen33UpdateHourOff();
    Screen33UpdateMinuteOff();    

 }

 void Screen33UpdateHourOn(){
  
   tft.fillRect(10,70,145,42,BLACK);
   if(RL4HourOnPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(25,82);
   if(RL4ConfigHourOn < 10){tft.print("0"); tft.print(RL4ConfigHourOn);}else{tft.print(RL4ConfigHourOn);}
   tft.setTextSize(2);
   tft.setCursor(80,82);
   tft.print("Horas");

 }
 void Screen33UpdateMinuteOn(){

   tft.fillRect(10,130,145,50,BLACK);
   if(RL4MinuteOnPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(25,147);
   if(RL4ConfigMinuteOn < 10){tft.print("0"); tft.print(RL4ConfigMinuteOn);}else{tft.print(RL4ConfigMinuteOn);}
   tft.setTextSize(2);
   tft.setCursor(71,147);
   tft.print("Minutos");
 
 }
 void Screen33UpdateHourOff(){

   tft.fillRect(165,70,145,42,BLACK);
   if(RL4HourOffPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(179,82);
   if(RL4ConfigHourOff < 10){tft.print("0"); tft.print(RL4ConfigHourOff);}else{tft.print(RL4ConfigHourOff);}
   tft.setTextSize(2);
   tft.setCursor(234,82);
   tft.print("Horas");
 
 }
 void Screen33UpdateMinuteOff(){

   tft.fillRect(165,130,145,50,BLACK);
   if(RL4MinuteOffPressed==true){tft.setTextColor(YELLOW);}else{tft.setTextColor(WHITE);}
   tft.setTextSize(3);
   tft.setCursor(179,147);
   if(RL4ConfigMinuteOff < 10){tft.print("0"); tft.print(RL4ConfigMinuteOff);}else{tft.print(RL4ConfigMinuteOff);}
   tft.setTextSize(2);
   tft.setCursor(225,147);
   tft.print("Minutos");
   
 }

  void Screen34(){

   PrintScreenLayout();
    
// Linhas para escrever titulos
    tft.drawLine(5,36,315,36,WHITE);
    tft.drawLine(5,37,315,37,WHITE); 

    tft.setCursor(75,12);
    tft.setTextColor(GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Configurar LCD");

    tft.drawLine(5,85,315,85,WHITE);// Linha para titulos
    tft.drawLine(5,86,315,86,WHITE);

   //Escrever Segundo Titulo 
    tft.setCursor(30,55);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Ligar Protecao de Ecra"); 

 //Escrever Valor Screen Saver Timeout
    Screen34Update();

    tft.setCursor(50,182);
    tft.setTextColor(YELLOW);
    tft.setTextSize(1);
    tft.print("Valor Minimo:5Min      Valor Maximo:90Min");             
  }

  void Screen34Update(){
    
    tft.fillRect(30,105,250,60,BLACK);
    tft.setTextColor(WHITE);
    
    if(ScreenSaverTimeout ==0){
      tft.setCursor(78,125);   
      tft.setTextSize(3);
      tft.print("Desligado");
    }
    else if(ScreenSaverTimeout >0 && ScreenSaverTimeout <10){
      tft.setCursor(129,125);
      tft.setTextSize(4);
      tft.print(ScreenSaverTimeout);
      tft.setCursor(165,130);  
      tft.setTextSize(3);
      tft.print("Min");
    }
      
    else if(ScreenSaverTimeout >=10){
      tft.setCursor(115,125);
      tft.setTextSize(4);
      tft.print(ScreenSaverTimeout);
      tft.setCursor(170,130);  
      tft.setTextSize(3);
      tft.print("Min");
    }
        
  } 

  void PrintMachineStatus(){

   pinMode(XM, OUTPUT);
   pinMode(YP, OUTPUT);

//*** Desenhar botões de funcionamento

// Modo Automatico    
   if (MachineStatus == 1){tft.fillRect(12,95,144,40,GREEN);}else{tft.fillRect(12,95,144,40,RED);}
    tft.drawRect(12,95,144,40,WHITE);
    tft.drawRect(11,96,144,38,WHITE);    
    tft.setCursor(24,107);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Automatico");
        
// Modo Manual   
   if (MachineStatus == 0){tft.fillRect(163,95,147,40,GREEN);}else{tft.fillRect(163,95,147,40,RED);}
    tft.drawRect(163,95,147,40,WHITE);
    tft.drawRect(162,96,147,38,WHITE);    
    tft.setCursor(202,107);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("Manual");

// ******Modo de Funcionameto
// Desenhar lima em cima/baixo de botoes para descrever modo de funcionamento da máquina
    tft.drawLine(5,85,315,85,WHITE);
    tft.drawLine(5,86,315,86,WHITE);

    if(Flg_TempHumAlarm==false && Flg_RTCAlarm==false){
       tft.setCursor(68,63);
       tft.setTextColor(YELLOW);
       tft.setTextSize(2);
       tft.fillRect(10,60,300,22,BLACK);
       if (MachineStatus==1){ tft.print("Modo Automatico");}
       if (MachineStatus==0){ tft.print("  Modo Manual");}
    }
    else if(Flg_TempHumAlarm==true){
       tft.setCursor(35,63);
       tft.setTextColor(RED);
       tft.setTextSize(2);
       tft.fillRect(10,60,300,22,BLACK);
       tft.print("!!Erro: Temperatura!!"); 
    }
    else if(Flg_RTCAlarm==true){
       tft.setCursor(34,63);
       tft.setTextColor(RED);
       tft.setTextSize(2);
       tft.fillRect(10,60,300,22,BLACK);
       tft.print("!!Erro: Data & Hora!!");       
    }
      
    tft.drawLine(5,143,315,143,WHITE);
    tft.drawLine(5,144,315,144,WHITE); 
  }


  void PrintOutputStatus(){

//**** Estado do Contacto Relé de Saída
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
   
 if(CurrentScreen==1){

       tft.drawLine(158,143,158,192,WHITE); // Linha a dividir 
       tft.drawLine(159,143,159,192,WHITE);
       
       tft.setTextColor(WHITE);
       tft.setTextSize(2);

    if(DisplayOutputsScreen1==1){

       tft.setCursor(168,149);
       tft.print("Saida RL3:");
       tft.setCursor(168,175);
       tft.print("Saida RL4:");
    
       if(RL3OutputControl== 1 && RL3OutputStatus == 1){tft.fillCircle(300,155,7,GREEN);}
       if(RL3OutputControl== 1 && RL3OutputStatus == 0){tft.fillCircle(300,155,7,RED);}
       if(RL3OutputControl== 2 && RL3OutputStatus == 1){tft.fillCircle(300,155,7,RED);}
       if(RL3OutputControl== 2 && RL3OutputStatus == 0){tft.fillCircle(300,155,7,GREEN);} 
      
       if(RL4OutputControl== 1 && RL4OutputStatus == 1){tft.fillCircle(300,182,7,GREEN);}
       if(RL4OutputControl== 1 && RL4OutputStatus == 0){tft.fillCircle(300,182,7,RED);}
       if(RL4OutputControl== 2 && RL4OutputStatus == 1){tft.fillCircle(300,182,7,RED);}
       if(RL4OutputControl== 2 && RL4OutputStatus == 0){tft.fillCircle(300,182,7,GREEN);}   
    }          
    else{  
      if(SDCardOk==false){ 
         tft.setCursor(168,149);
         tft.print("Aqc. Agua:");
         tft.setCursor(168,175);
         tft.print("Aqc. Casa:");
      }
      else{
         bmpDraw("Valve.bmp",160,145);
         tft.setCursor(168,149);
         tft.print("     Agua:");
         tft.setCursor(168,175);
         tft.print("     Casa:");
         tft.drawLine(212,169,315,169,WHITE); // Linha a dividir 
         tft.drawLine(212,170,315,170,WHITE);          
        }   
       if(TemperatureControl== 1 && RL1OutputStatus == 0){tft.fillCircle(300,155,7,GREEN);}
       if(TemperatureControl== 1 && RL1OutputStatus == 1){tft.fillCircle(300,155,7,RED);}
       if(TemperatureControl== 2 && RL1OutputStatus == 0){tft.fillCircle(300,155,7,RED);}
       if(TemperatureControl== 2 && RL1OutputStatus == 1){tft.fillCircle(300,155,7,GREEN);} 
      
       if(TemperatureControl== 1 && RL1OutputStatus == 1){tft.fillCircle(300,182,7,GREEN);}
       if(TemperatureControl== 1 && RL1OutputStatus == 0){tft.fillCircle(300,182,7,RED);}
       if(TemperatureControl== 2 && RL1OutputStatus == 1){tft.fillCircle(300,182,7,RED);}
       if(TemperatureControl== 2 && RL1OutputStatus == 0){tft.fillCircle(300,182,7,GREEN);}  
    }        
  } 
         
    if(CurrentScreen==5){   
        RL1OutputStatus = digitalRead(DO_Temperature);
        tft.fillRect(162,98,151,38,BLACK);
        tft.setTextSize(3);
               
        if(TemperatureControl== 1 && RL1OutputStatus == 1){
          tft.fillCircle(235,157,15,GREEN);
          tft.setCursor(200,108);
          tft.print("CASA");
        }
        if(TemperatureControl== 1 && RL1OutputStatus == 0){
          tft.fillCircle(235,157,15,RED);
          tft.setCursor(200,108);
          tft.print("AGUA");
        }
        if(TemperatureControl== 2 && RL1OutputStatus == 1){
          tft.fillCircle(235,157,15,RED);
          tft.setCursor(200,108);
          tft.print("AGUA");
        }
        if(TemperatureControl== 2 && RL1OutputStatus == 0){
          tft.fillCircle(235,157,15,GREEN);
          tft.setCursor(200,108);
          tft.print("CASA");
        }      
    } 

    if(CurrentScreen==15){
      RL2OutputStatus = digitalRead(DO_Humidity);
      if(HumidityControl== 1 && RL2OutputStatus == 1){tft.fillCircle(235,140,15,GREEN);}
      if(HumidityControl== 1 && RL2OutputStatus == 0){tft.fillCircle(235,140,15,RED);}
      if(HumidityControl== 2 && RL2OutputStatus == 1){tft.fillCircle(235,140,15,RED);}
      if(HumidityControl== 2 && RL2OutputStatus == 0){tft.fillCircle(235,140,15,GREEN);}       
    }

    if(CurrentScreen==17){
      if(TemperatureControl== 1 && RL1OutputStatus == 1){tft.fillCircle(287,90,9,GREEN);}
      if(TemperatureControl== 1 && RL1OutputStatus == 0){tft.fillCircle(287,90,9,RED);}
      if(TemperatureControl== 2 && RL1OutputStatus == 1){tft.fillCircle(287,90,9,RED);}
      if(TemperatureControl== 2 && RL1OutputStatus == 0){tft.fillCircle(287,90,9,GREEN);} 
  
      if(HumidityControl== 1 && RL2OutputStatus == 1){tft.fillCircle(287,120,9,GREEN);}
      if(HumidityControl== 1 && RL2OutputStatus == 0){tft.fillCircle(287,120,9,RED);}
      if(HumidityControl== 2 && RL2OutputStatus == 1){tft.fillCircle(287,120,9,RED);}
      if(HumidityControl== 2 && RL2OutputStatus == 0){tft.fillCircle(287,120,9,GREEN);}

      if(RL3OutputControl== 1 && RL3OutputStatus == 1){tft.fillCircle(287,150,9,GREEN);}
      if(RL3OutputControl== 1 && RL3OutputStatus == 0){tft.fillCircle(287,150,9,RED);}
      if(RL3OutputControl== 2 && RL3OutputStatus == 1){tft.fillCircle(287,150,9,RED);}
      if(RL3OutputControl== 2 && RL3OutputStatus == 0){tft.fillCircle(287,150,9,GREEN);}  

      if(RL4OutputControl== 1 && RL4OutputStatus == 1){tft.fillCircle(287,180,9,GREEN);}
      if(RL4OutputControl== 1 && RL4OutputStatus == 0){tft.fillCircle(287,180,9,RED);}
      if(RL4OutputControl== 2 && RL4OutputStatus == 1){tft.fillCircle(287,180,9,RED);}
      if(RL4OutputControl== 2 && RL4OutputStatus == 0){tft.fillCircle(287,180,9,GREEN);}                     
    } 

    if(CurrentScreen==25){
      RL3OutputStatus = digitalRead(DO_RL3);
      if(RL3OutputControl== 1 && RL3OutputStatus == 1){tft.fillCircle(162,135,20,GREEN);}
      if(RL3OutputControl== 1 && RL3OutputStatus == 0){tft.fillCircle(162,135,20,RED);}
      if(RL3OutputControl== 2 && RL3OutputStatus == 1){tft.fillCircle(162,135,20,RED);}
      if(RL3OutputControl== 2 && RL3OutputStatus == 0){tft.fillCircle(162,135,20,GREEN);}       
    }

    if(CurrentScreen==26){
      RL4OutputStatus = digitalRead(DO_RL4);
      if(RL4OutputControl== 1 && RL4OutputStatus == 1){tft.fillCircle(162,135,20,GREEN);}
      if(RL4OutputControl== 1 && RL4OutputStatus == 0){tft.fillCircle(162,135,20,RED);}
      if(RL4OutputControl== 2 && RL4OutputStatus == 1){tft.fillCircle(162,135,20,RED);}
      if(RL4OutputControl== 2 && RL4OutputStatus == 0){tft.fillCircle(162,135,20,GREEN);}       
    }
    
  }

  void AutoTempControl(){

  if(Flg_TempHumAlarm==false){
     if (Temperature >= TemperatureMax){                         
          if(TemperatureControl==1){digitalWrite(DO_Temperature,HIGH);}             
          if(TemperatureControl==2){digitalWrite(DO_Temperature,LOW);}         
     } 
     if (Temperature <= TemperatureMin){         
         if(TemperatureControl==1){digitalWrite(DO_Temperature,LOW);}   
         if(TemperatureControl==2){digitalWrite(DO_Temperature,HIGH);}           
     }
  }
  else{
    if(TemperatureControl==1){digitalWrite(DO_Temperature,LOW);}
    if(TemperatureControl==2){digitalWrite(DO_Temperature,HIGH);}
  }
   
  }

  void AutoHumControl(){
        
     if (Humidity >= HumidityMax  || Flg_TempHumAlarm==true){                         
         if(HumidityControl==1){digitalWrite(DO_Humidity,LOW);}             
         if(HumidityControl==2){digitalWrite(DO_Humidity,HIGH);}                               
     } 
     if (Humidity <= HumidityMin && Flg_TempHumAlarm==false){         
         if(HumidityControl==1){digitalWrite(DO_Humidity,HIGH);}   
         if(HumidityControl==2){digitalWrite(DO_Humidity,LOW);}           
     }   
  }

  void AutoRL3Control(){

         switch (Aux_DayOfTheWeek) 
      {
         case 0:
             if(RL3ConfigSun==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();}          
         break;         
         case 1:
             if(RL3ConfigMon==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();}      
         break;
         case 2:
             if(RL3ConfigTue==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();} 
         break;
         case 3:
             if(RL3ConfigWed==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();}          
         break;
         case 4:
             if(RL3ConfigThu==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();} 
         break;
         case 5:
             if(RL3ConfigFri==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();}          
         break;
         case 6:
             if(RL3ConfigSat==1){
                 if((((Hour>=RL3ConfigHourOn && Hour<RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn)|| Hour>RL3ConfigHourOn && Hour==RL3ConfigHourOff && Minute<RL3ConfigMinuteOff)|| Hour>=RL3ConfigHourOn && Hour<=RL3ConfigHourOff &&  Minute>=RL3ConfigMinuteOn && Minute<RL3ConfigMinuteOff)){
                    RL3OutputOn();
                 }
                 else{
                    RL3OutputOff();
                 }
             }
             else{RL3OutputOff();}          
         break;                                                      
      } 
  }

  void RL3OutputOn(){
     if(RL3OutputControl==1){digitalWrite(DO_RL3,HIGH);}
     if(RL3OutputControl==2){digitalWrite(DO_RL3,LOW);}        
  }

  void RL3OutputOff(){
     if(RL3OutputControl==1){digitalWrite(DO_RL3,LOW);}
     if(RL3OutputControl==2){digitalWrite(DO_RL3,HIGH);}  
  }

  void AutoRL4Control(){
    
         switch (Aux_DayOfTheWeek) 
      {
         case 0:
             if(RL4ConfigSun==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();}        
         break;          
         case 1:
             if(RL4ConfigMon==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();}      
         break;
         case 2:
             if(RL4ConfigTue==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();} 
         break;
         case 3:
             if(RL4ConfigWed==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();}          
         break;
         case 4:
             if(RL4ConfigThu==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();} 
         break;
         case 5:
             if(RL4ConfigFri==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();}        
         break;
         case 6:
             if(RL4ConfigSat==1){
                 if((((Hour>=RL4ConfigHourOn && Hour<RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn)|| Hour>RL4ConfigHourOn && Hour==RL4ConfigHourOff && Minute<RL4ConfigMinuteOff)|| Hour>=RL4ConfigHourOn && Hour<=RL4ConfigHourOff &&  Minute>=RL4ConfigMinuteOn && Minute<RL4ConfigMinuteOff)){
                    RL4OutputOn();
                 }
                 else{
                    RL4OutputOff();
                 }
             }
             else{RL4OutputOff();}          
         break;                                                     
      } 
  }

  void RL4OutputOn(){
     if(RL4OutputControl==1){digitalWrite(DO_RL4,HIGH);}
     if(RL4OutputControl==2){digitalWrite(DO_RL4,LOW);}        
  }

  void RL4OutputOff(){
     if(RL4OutputControl==1){digitalWrite(DO_RL4,LOW);}
     if(RL4OutputControl==2){digitalWrite(DO_RL4,HIGH);}  
  }

// :::::::::::::::::::::::: Rotina RTC - Obter Data e Hora :::::::::::::::::::::::::::
  void ReadRTC(){

    DateTime now = rtc.now();
    Year=now.year();
    Month=now.month();
    Day=now.day();
    DaysOfTheWeek=(daysOfTheWeek[now.dayOfTheWeek()]);
    Hour=now.hour();
    Minute=now.minute();
    Second=now.second();
    Aux_DayOfTheWeek= now.dayOfTheWeek();

    if(!rtc.isrunning() || Minute==165 || Day==0 ){
      Flg_RTCAlarm=true;
      if(MachineStatus==1){RL3OutputOff();}
      if(MachineStatus==1){RL4OutputOff();}
    }
    else{
      Flg_RTCAlarm=false;     
    }

    if (Minute!=Minute_old & CurrentScreen==1){
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      PrintDateTime();
      Minute_old=Minute;    
    }  
  }

// :::::::::::::::::::::::: Pedido para Escrever Data e Hora no Ecra Principal :::::::::::::::::::::::::::
  void PrintDateTime(){

   if (Flg_RTCAlarm==true && CurrentScreen==1){
      tft.fillRect(10,149,143,40,BLACK);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.setCursor(23,160);
      tft.print("!!!Erro!!!");        
    }

   else if(Flg_RTCAlarm==false && CurrentScreen==1){
      tft.fillRect(10,149,143,40,BLACK); 
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.setCursor(22,150);
      if(Day<10){tft.print("0");
      tft.print(Day);}
      if(Day>=10){tft.print(Day);}
      tft.print("/");
      if(Month<10){tft.print("0");
      tft.print(Month);}
      if(Month>=10){tft.print(Month);}
      tft.print("/");
      tft.print(Year);
      tft.setCursor(28,172);
      tft.print(DaysOfTheWeek);
      tft.print(" ");
      if(Hour<10){tft.print("0");
      tft.print(Hour);}
      if(Hour>=10){tft.print(Hour);}
      tft.print(":");
      if(Minute<10){tft.print("0");
      tft.print(Minute);}
      if(Minute>=10){tft.print(Minute);}
    } 
  }
  
// :::::::::::::::::::::::: Guardar valores na EEPROM para Gráfico de Temperatura :::::::::::::::::::::::::::
  void GraphSaveTemperature(){
      int Aux1; 
      Aux1 = 100 + Hour*4 + Minute/15;
      GraphPointer=Aux1;
      EEPROM.update(Aux1,Temperature);
// Chamada para Atualizar Gráfico de Temperatura 
      if(CurrentScreen==3){Screen3GraphRefresh();}
// Chamada para Atualizar Gráfico de Temperatura e Humidade 
      if(CurrentScreen==19){Screen3GraphRefresh();Screen13GraphRefresh();}       
 } 

// :::::::::::::::::::::::: Guardar valores na EEPROM para Gráfico de Humidade :::::::::::::::::::::::::::
 void GraphSaveHumidity(){
    int Aux2; 
    Aux2 = 200 + Hour*4 + Minute/15;
    GraphPointer1=Aux2;
    EEPROM.update(Aux2,Humidity);        
//  Chamada para Atualizar Gráfico de Humidade 
     if(CurrentScreen==13){Screen13GraphRefresh();}
//  Chamada para Atualizar Gráfico de Humidade e Temperatura 
     if(CurrentScreen==19){Screen3GraphRefresh();Screen13GraphRefresh();}         
 } 
 
// :::::::::::::::::::::::: Guardar valores de Temperatura na EEPROM para Eventos do Ecra 20 - Tabela :::::::::::::::::::::::::::
  void SaveTempEventData(){
     int Aux1;
     int Aux2;
     int T_Aux1;
     int T_Aux2;
     int T_Aux3;
     
     T_Aux1 = Temperature,1*10;
     T_Aux2 = Temperature*10;
     T_Aux3= T_Aux1*10;
     TemperatureDec =T_Aux2-T_Aux3;
      
     Aux1 = 300 + Hour*4 + Minute/15;
     Aux2 = 500 + Hour*4 + Minute/15;
     EEPROM.update(Aux1,Temperature);
     EEPROM.update(Aux2,TemperatureDec);
  }
  
// :::::::::::::::::::::::: Guardar valores de Humidade na EEPROM para Eventos do Ecra 20 - Tabela :::::::::::::::::::::::::::
  void SaveHumEventData(){
     int Aux1;
     int Aux2;
     int H_Aux1;
     int H_Aux2;
     int H_Aux3;
          
     H_Aux1 = Humidity,1*10;
     H_Aux2 = Humidity*10;
     H_Aux3= H_Aux1*10;
     HumidityDec =H_Aux2-H_Aux3;
     
     Aux1 = 400 + Hour*4 + Minute/15;
     Aux2 = 600 + Hour*4 + Minute/15;
     EEPROM.update(Aux1,Humidity);
     EEPROM.update(Aux2,HumidityDec);
  }

// :::::::::::::::::::::::: Reset das memorias para escrita do grafico Temperatura  :::::::::::::::::::::::::::  
 void GraphTempValuesReset(){
    for(int c=100; c<=195; c++){
      EEPROM.write(c,0);
    }
    if(CurrentScreen==3){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);      
      CurrentScreen=3;
      Screen3();
     } 
    if(CurrentScreen==19){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);      
      CurrentScreen=19;
      Screen19();
    }       
  }

// :::::::::::::::::::::::: Reset das memorias para escrita do grafico Humidade :::::::::::::::::::::::::::
  void GraphHumValuesReset(){ 
    for(int c=200; c<=295; c++){
      EEPROM.write(c,0);
    }
    if(CurrentScreen==13){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);      
      CurrentScreen=13;
      Screen13();
    } 
    if(CurrentScreen==19){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);      
      CurrentScreen=19;
      Screen19();
    }           
  }
  
// :::::::::::::::::::::::: Reset das memorias para escreita de Eventos de Temperatura no Ecra 20 - Tabela :::::::::::::::::::::::::::
  void TempEventDataReset(){
    for(int c=300; c<=395; c++){
      EEPROM.write(c,0);
    }
    for(int c=500; c<=595; c++){
      EEPROM.write(c,0);
    }
  }
  
// :::::::::::::::::::::::: Reset das memorias para escreita de Eventos de Humidade no Ecra 20 - Tabela :::::::::::::::::::::::::::  
  void HumEventDataReset(){
    for(int c=400; c<=495; c++){
      EEPROM.write(c,0);
    }
    for(int c=600; c<=695; c++){
      EEPROM.write(c,0);
    }
    if(CurrentScreen==20){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);      
      CurrentScreen=20;
      Screen20();
    }
  }
// :::::::::::::::::::::::::::::::::::::::: Intervalo de Tempo programado para chamar rotina Guardar Eventos no Ficheiro Txt no Cartão SD :::::::::::::::::::::::::::::::::::::::::::::::::
  void GetEventsRegInterval(){

     switch (EventsRegInterval) 
      { 
         case 1:
            if(Minute==0 || Minute==1 || Minute==2 || Minute==3 || Minute==4 || Minute==5 || Minute==6 || Minute==7 || Minute==8 || Minute==9 || Minute==10 || Minute==11 || Minute==12 || Minute==13 || Minute==14 || Minute==15 || Minute==16 || Minute==17 || Minute==18 || Minute==19 || Minute==20 || Minute==21 || Minute==22 || Minute==23 || Minute==24 || Minute==25 || Minute==26 || Minute==27 || Minute==28 || Minute==29 || Minute==30 || Minute==31 || Minute==32 || Minute==33 || Minute==34 || Minute==35 || Minute==36 || Minute==37 || Minute==38 || Minute==39 || Minute==40 || Minute==41 || Minute==42 || Minute==43 || Minute==44 || Minute==45 || Minute==46 || Minute==47 || Minute==48 || Minute==49 || Minute==50 || Minute==51 || Minute==52 || Minute==53 || Minute==54 || Minute==55 || Minute==56 || Minute==57 || Minute==58 || Minute==59){EventRegister();}  
         break;        
         case 2:
            if(Minute==0 || Minute==2 || Minute==4 || Minute==6 || Minute==8 || Minute==10 || Minute==12 || Minute==14 || Minute==16 || Minute==18 || Minute==20 || Minute==22 || Minute==24 || Minute==26 || Minute==28 || Minute==30 || Minute==32 || Minute==34 || Minute==36 || Minute==38 || Minute==40 || Minute==42 || Minute==44 || Minute==46 || Minute==48 || Minute==50 || Minute==52 || Minute==54 || Minute==56 || Minute==58){EventRegister();}          
         break;         
         case 3:
            if(Minute==0 || Minute==3 || Minute==6 || Minute==9 || Minute==12 || Minute==15 || Minute==18 || Minute==21 || Minute==24 || Minute==27 || Minute==30 || Minute==33 || Minute==36 || Minute==39 || Minute==42 || Minute==45 || Minute==48 || Minute==51 || Minute==54 || Minute==57){EventRegister();}          
         break;         
         case 4:
            if(Minute==0 || Minute==4 || Minute==8 || Minute==12 || Minute==16 || Minute==20 || Minute==24 || Minute==28 || Minute==32 || Minute==36 || Minute==40 || Minute==44 || Minute==48 || Minute==52 || Minute==56){EventRegister();}         
         break;                  
         case 5:
             if(Minute==0 || Minute==5 || Minute==10 || Minute==15 || Minute==20 || Minute==25 || Minute==30 || Minute==35 || Minute==40 || Minute==45 || Minute==50 || Minute==55){EventRegister();}           
         break;
         case 10:
             if(Minute==0 || Minute==10 || Minute==20 || Minute==30 || Minute==40 || Minute==50){EventRegister();} 
         break;
         case 15:
             if(Minute==0 || Minute==15 || Minute==30 || Minute==45){EventRegister();} 
         break;
         case 20:
             if(Minute==0 || Minute==20 || Minute==40){EventRegister();} 
         break;
         case 30:
             if(Minute==0 || Minute==30){EventRegister();}           
         break;
         case 60:
             if(Minute==0){EventRegister();}           
         break;                                    
      }
  }


// :::::::::::::::::::::::::::::::::::::::: Registo da Temperatura e Humidade para Cartao SD em Ficheiro Txt :::::::::::::::::::::::::::::::::::::::::::::::::

void EventRegister(){
  
  if(Old_Minute!=Minute){

      GetFileName();
      myFile = SD.open(FileName,FILE_WRITE); // Open/Create File in SD card
      
// if the file opened okay, write to it:   
        if(myFile) {
           myFile.print("|");
           if(Day<=9){myFile.print("0"); myFile.print(Day);}else{myFile.print(Day);}    
           myFile.print("|");
           if(Month<=9){myFile.print("0"); myFile.print(Month);}else{myFile.print(Month);}
           myFile.print("|");
           myFile.print(Year);
           myFile.print("|");
           if(Hour<=9){myFile.print("0"); myFile.print(Hour);}else{myFile.print(Hour);}
           myFile.print("|");
           if(Minute<=9){myFile.print("0"); myFile.print(Minute);}else{myFile.print(Minute);}
           myFile.print("|");
           myFile.print(Temperature,1);
           //myFile.print("|");
           //myFile.print(Humidity,1);
              
           myFile.close();
        }

     Old_Minute=Minute;
  }
}

// ::::::::::::::::::::::::::::::::::::::::::::::: Enviar Registos do Cartão SD pedidos pelo Visual Basic ::::::::::::::::::::::::::::::::::::::::::::::::::
 void SendEventRegData(){
    if(SDCardOk==true){
        if (SD.exists(VBRequestFileName)) {
            myFile = SD.open(VBRequestFileName);
              if (myFile) {
                Serial.print("@WSED");
                while (myFile.available()) {
                  Serial.write(myFile.read());
                }
                myFile.close();
                Serial.print("|@");
              } else {
                Serial.write("@WSOFE@");// Open File Error
              }
        }
        else{
          Serial.write("@WSNFF@");// No File Found
        }
    }
    else{
       Serial.write("@WSNCF@");// No card Found
    }
 }

// ::::::::::::::::::::::::::::::::::::::::: Apagar Registos Guardados no Cartão SD :::::::::::::::::::::::::::::::::::::::::::::::::
 void DeleteEventRegDataFile(){
    if(SDCardOk==true){
        if (SD.exists(VBRequestFileName)) {
            SD.remove(VBRequestFileName);
               if (!SD.exists(VBRequestFileName)) {
                    Serial.write("@WSSDFD@");// Done ok  
               }
        } 
         else{
            Serial.write("@WSNFF@");   // No File Found
         }
    }
    else{
      Serial.write("@WSNCF@"); // No Card Found
    }
           
}

// ::::::::::::::::::::::::::::::::::::::: Receber Comandos Enviados Pelo Visual Basic ::::::::::::::::::::::::::::::::::::::::::::::::
  void VBDataRequest() {

   myChar[myCharPoinrer] = Serial.read();
   myCharPoinrer++;

   // Read Serial Events Data Request
     if(myChar[0]=='@' & myChar[1]=='R' & myChar[2]=='S'& myChar[3]=='E'& myChar[4]=='D' & myChar[13]=='@' &(!Serial.available())){ //read serial events data from File
        
          VBRequestFileName[0]= myChar[5];
          VBRequestFileName[1]= myChar[6];
          VBRequestFileName[2]= myChar[7];
          VBRequestFileName[3]= myChar[8];
          VBRequestFileName[4]= myChar[9];
          VBRequestFileName[5]= myChar[10];
          VBRequestFileName[6]= myChar[11];
          VBRequestFileName[7]= myChar[12];
          VBRequestFileName[8]='.';
          VBRequestFileName[9]='t';
          VBRequestFileName[10]='x';
          VBRequestFileName[11]='t';
          
          SendEventRegData();
          
          for(int c=0; c<=19; c++){
           myChar[c]= "0";
          }
           myCharPoinrer=0;
      }
      // SD File Delete Request
     else if(myChar[0]=='@' & myChar[1]=='R' & myChar[2]=='S'& myChar[3]=='F'& myChar[4]=='D' & myChar[13]=='@' &(!Serial.available())){ //Delete File From SD (SD File Delete)
        
          VBRequestFileName[0]= myChar[5];
          VBRequestFileName[1]= myChar[6];
          VBRequestFileName[2]= myChar[7];
          VBRequestFileName[3]= myChar[8];
          VBRequestFileName[4]= myChar[9];
          VBRequestFileName[5]= myChar[10];
          VBRequestFileName[6]= myChar[11];
          VBRequestFileName[7]= myChar[12];
          VBRequestFileName[8]='.';
          VBRequestFileName[9]='t';
          VBRequestFileName[10]='x';
          VBRequestFileName[11]='t';
          
          DeleteEventRegDataFile();
          
          for(int c=0; c<=19; c++){
           myChar[c]= "0";
          }
           myCharPoinrer=0;
      } 
           // Read Serial Number Request
      else if(myChar[0]=='@' & myChar[1]=='R' & myChar[2]=='S'& myChar[3]=='S'& myChar[4]=='N' & myChar[5]=='@' &(!Serial.available())){//read serial serial number                   
            for(int c=0; c<=19; c++){
               myChar[c]= "0";
            }
          Serial.print("@WSSN");
          Serial.print(StrDeviceInfo);
          Serial.print("|@"); 
          myCharPoinrer=0;
      }
      
     else if(!Serial.available()){ // Command Not Received
          for(int c=0; c<=19; c++){
           myChar[c]= "0";
          }
           myCharPoinrer=0;
           Serial.write("@WSCNR@");          
      }        
  }

// ::::::::::::::::::::::::::::::::::::::::::: Registar Eventos: Obter Nome Do Ficheiro a ser guardado/lido no Cartao SD  ::::::::::::::::::::::::::::::::::::::::::::

  void GetFileName(){

    FileName[0] = Day/10 + '0';
    FileName[1] = Day%10 + '0';
    FileName[2] = Month/10 + '0';
    FileName[3] = Month%10 + '0';
    FileName[4] = '2';
    FileName[5] = '0';
    FileName[6] = (Year-2000)/10 + '0';
    FileName[7] = Year%10 + '0';
    FileName[8] ='.';
    FileName[9] ='t';
    FileName[10] ='x';
    FileName[11] ='t';
  
  }

//************************************************* Ecra Screen Saver  *********************************************   
  
  void Screen100(){ // Protecao de Ecra 
  
    int x = random(5, 170);
    int y = random(5, 170);

    tft.fillScreen(BLACK);
    //tft.drawRect(x-4,y-4,149,44,WHITE);
    //tft.drawRect(x-5,y-5,151,46,WHITE);
    tft.setTextColor(YELLOW);
    tft.setTextSize(5);  
    tft.setCursor(x, y);
    if(Temperature<100 && Flg_TempHumAlarm==false){tft.println(Temperature,1);}
    else if(Temperature>=100 && Flg_TempHumAlarm==false){tft.println(Temperature,0);}
    else if(Flg_TempHumAlarm==true){tft.println("##.#");}
    tft.setTextSize(2);
    tft.setCursor(x+119, y-4);
    tft.print("o");
    tft.setCursor(x+131, y+7);
    tft.print("C");       
  }

  //************************************************* Ecra Inicial de Apresentação********************************************* 

  void Screen101(){
    tft.fillScreen(BLACK);
    tft.drawRect(5,3,312,234,WHITE);
    tft.drawRect(4,4,312,232,WHITE);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(33, 15);
    tft.print("ATMega Temp-04");
    tft.drawLine(17,42,301,42,RED);
    tft.drawLine(17,43,301,43,RED);
    tft.drawLine(17,44,301,44,RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(95, 53);
    tft.print("Controlador");
    tft.setTextSize(3);
    tft.setCursor(152,83);
    tft.print("&");
    tft.setTextSize(2);
    tft.setCursor(102,118);
    tft.print("Registador");
    if(SDCardOk==true){
        bmpDraw("Logo.bmp", 113, 145);
    }
    else{
       tft.drawRect(105,147,108,75,RED);
       tft.drawLine(105,183,211,183,RED);
       tft.setTextColor(WHITE);      
       tft.setTextSize(2);
       tft.setCursor(141,150);
       tft.print("o");
       tft.setTextSize(3);
       tft.setCursor(154,155);   
       tft.print("C");
       tft.setTextSize(3);
       tft.setCursor(122,192);
       tft.print("Agua");          
    }
  }
  
//************************************************* Função Apenas Chamada para Programar Cordenadas para Touch Screen *********************************************
  void TouchButtonTeach(){
      TSPoint p = ts.getPoint();
        if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
          Serial.print("X= ");      
          Serial.println(p.x);
          Serial.print("Y= ");
          Serial.println(p.y); 
          delay(1000);
        }
  }

//************************************************* Carregar Bitmap Logo no arranque do Controlador *********************************************

#define BUFFPIXEL 20

void bmpDraw(char *filename, int x, int y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel in buffer (R+G+B per pixel)
  uint16_t lcdbuffer[BUFFPIXEL];  // pixel out buffer (16-bit per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();
  uint8_t  lcdidx = 0;
  boolean  first = true;

  if((x >= tft.width()) || (y >= tft.height())) return;


  if ((bmpFile = SD.open(filename)) == NULL) {
    Serial.println(F("File not found"));
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.println(F("File size: ")); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print(F("Image Offset: ")); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print(F("Header size: ")); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print(F("Bit Depth: ")); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        Serial.print(F("Image size: "));
        Serial.print(bmpWidth);
        Serial.print('x');
        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x+w-1, y+h-1);

        for (row=0; row<h; row++) { // For each scanline...
          
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each column...
            // Time to read more pixel data?
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              // Push LCD buffer to the display first
              if(lcdidx > 0) {
                tft.pushColors(lcdbuffer, lcdidx, first);
                lcdidx = 0;
                first  = false;
              }
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            lcdbuffer[lcdidx++] = tft.color565(r,g,b);
          } // end pixel
        } // end scanline
        // Write any remaining data to LCD
        if(lcdidx > 0) {
          tft.pushColors(lcdbuffer, lcdidx, first);
        } 

      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println(F("BMP format not recognized."));
}

uint16_t read16(File f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}
