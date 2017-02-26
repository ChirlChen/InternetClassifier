#ifndef _DATASTRUCTDE_H_
#define _DATASTRUCTDE_H_
#include <string>
/*****************枚举定义*****************/
enum ECheckBoxOrderNum    //CheckBox的序号枚举;
{
  ECBON_CheckBox0 = 4,
  ECBON_CheckBox11 = 8,
  ECBON_CheckBox2 = 50,
  ECBON_CheckBox10 = 60,
  ECBON_CheckBox3 = 72,
  ECBON_CheckBox4 = 91,
  ECBON_CheckBox15 = 170,
  ECBON_CheckBox16 = 190,
  ECBON_CheckBox5 = 108,
  ECBON_CheckBox13 = 210,
  ECBON_CheckBox6 = 113,
  ECBON_CheckBox12 = 220,
  ECBON_CheckBox7 = 155,
  ECBON_CheckBox14 = 230,
  ECBON_CheckBox8 = 202,
  ECBON_CheckBox9 = 250,
};

//WWW,FTP-PASV,SERVICES,INTERACTIVE,MAIL,
//  FTP-CONTROL,DATABASE,P2P,FTP-DATA;
enum ETrafficType   //网络流量分类类型;
{
  ETT_WWW,          //WWW型数据包;
  ETT_FTP,          //FTP型;
  ETT_MAIL,         //MAIL类型;
  ETT_P2P,          //P2P类型;
  ETT_ATTACK,       //ATTACK类型;
  ETT_DATABASE,     //DATABASE类型;
  ETT_SERVICES,     //SERVICES类型;
  ETT_INTERACTIVE,  //INTERACTIVE类型;
  ETT_MULTIMEDIA,   //MULTIMEDIA类型;
  ETT_ERR_TYPE,     //错误类型;
  ETT_ALL_TYPE,     //所有类型总数;
};

enum EPickOutAttriResult  //挑选属性值的结果;
{
  EPOAR_IsNum,  //传入的是属性值，但非需要的属性值;
  EPOAR_IsTarget, //传入的是我们需要查找的属性值;
  EPOAR_NotNum, //传入的不是数值;
};

enum EFileReadResult    //读取文件的结果返回;
{
  EFRR_ReadFileSucceed,       //读取成功;
  EFRR_FilePathIsNull,        //文件路径为空;
  EFRR_OpenFileFailed,        //打开文件失败;
  EFRR_NoNecessaryAttri,      //需求属性为空;
};

enum EOperateFlag  //标记操作类型（分类文件或训练文件）;
{
  EOF_Training,   //训练标记;
  EOF_Classify,   //分类标记;
  EOF_TrainingFinished, //训练结束;
  EOF_ClassifyFinished, //分类结束;
  EOF_NULL, //空数据;
};

/*****************常量定义*****************/
const short ATTRI_CHECKBOX_NUM = 16;    //分类属性的checkbox数量;
const int BUF_SIZE = 2048;   //读取文件的缓存大小;
const int TRAFFIC_TYPE_NUM_O = ETT_ALL_TYPE + 1;  //网络流量原始类型总数;
const int TRAFFIC_TYPE_NUM_C = ETT_ALL_TYPE + 1;  //网络流量分类结果类型总数;
const std::string MY_VERSION = "1.1.160116.beta"; //简单版本标识(系统架构变动.功能模块添加.bug修复或基础的程序变动日期.测试);

/*****************结构体定义***************/
typedef struct _SDataPack
{
  EOperateFlag aFlag;    //数据包类型;
  unsigned short *aSrcArray;    //属性组;
  int aSrcArraySize;      //属性组大小;
  char *aFilePath;    //数据文件路径;

  _SDataPack()
  {
    aFlag = EOF_NULL;
    aSrcArray = 0;
    aSrcArraySize = 0;
    aFilePath = 0;
  }
}SDataPack;

#endif