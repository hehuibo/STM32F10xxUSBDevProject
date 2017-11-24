/**
  ******************************************************************************
  * @file    usb_desc.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Descriptors for Custom HID 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* USB Standard Device Descriptor */
const uint8_t Composite_DeviceDescriptor[Composite_SIZ_DEVICE_DESC] =
  {
    0x12,                       /*bLength */
    USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/
    0x00,                       /*bcdUSB */
    0x02,
    0x00,                       /*bDeviceClass*/
    0x00,                       /*bDeviceSubClass*/
    0x00,                       /*bDeviceProtocol*/
    0x40,                       /*bMaxPacketSize 64*/
    0x83,                       /*idVendor (0x0483)*/
    0x04,
    0x10,                       /*idProduct = 0x5710*/
    0x57,
    0x00,                       /*bcdDevice rel. 2.00*/
    0x02,
    1,                          /*Index of string descriptor describing
                                              manufacturer */
    2,                          /*Index of string descriptor describing
                                             product*/
    3,                          /*Index of string descriptor describing the
                                             device serial number */
    0x01                        /*bNumConfigurations*/
  }
  ; /* Composite_DeviceDescriptor */


/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
const uint8_t Composite_ConfigDescriptor[Composite_SIZ_CONFIG_DESC] =
  {
    0x09, /* bLength: Configuation Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
    Composite_SIZ_CONFIG_DESC,
    /* wTotalLength: Bytes returned */
    0x00,
    0x02,         /* bNumInterfaces: 1 interface */
    0x01,         /* bConfigurationValue: Configuration value */
    0x00,         /* iConfiguration: Index of string descriptor describing the configuration*/
    0xC0,         /* bmAttributes: Bus powered */
                  /*Bus powered: 7th bit, Self Powered: 6th bit, Remote wakeup: 5th bit, reserved: 4..0 bits */
    0x32,         /* MaxPower 100 mA: this current is used for detecting Vbus */

    /*Custom HID.-->EnpAddr 1-2*/
    /************** Descriptor of Custom HID interface ****************/
    /* 09 */
    0x09,         /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,/* bDescriptorType: Interface descriptor type */
    0x00,         /* bInterfaceNumber: Number of Interface */
    0x00,         /* bAlternateSetting: Alternate setting */
    0x02,         /* bNumEndpoints */
    0x03,         /* bInterfaceClass: HID */
    0x00,         /* bInterfaceSubClass : 1=BOOT, 0=no boot */
    0x00,         /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
    4,            /* iInterface: Index of string descriptor */
    /******************** Descriptor of Custom HID HID ********************/
    /* 18 */
    0x09,         /* bLength: HID Descriptor size */
    HID_DESCRIPTOR_TYPE, /* bDescriptorType: HID */
    0x10,         /* bcdHID: HID Class Spec release number */
    0x01,
    0x00,         /* bCountryCode: Hardware target country */
    0x01,         /* bNumDescriptors: Number of HID class descriptors to follow */
    0x22,         /* bDescriptorType */
    CUSTOMHID_SIZ_REPORT_DESC,	/* wItemLength: Total length of Report descriptor */
    0x00,
    /******************** Descriptor of Custom HID endpoints ******************/
    /* 27 */
    0x07,          /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: */

    0x81,          /* bEndpointAddress: Endpoint Address (IN) */               
    0x03,          /* bmAttributes: Interrupt endpoint */
    0x20,          /* wMaxPacketSize: 64 Bytes max */
    0x00,
    0x20,          /* bInterval: Polling Interval (32 ms) */
    /* 34 */

    0x07,	/* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,	/* bDescriptorType: */
			/*	Endpoint descriptor type */
    0x01,	/* bEndpointAddress: */
			/*	Endpoint Address (OUT) */
    0x03,	/* bmAttributes: Interrupt endpoint */
    0x20,	/* wMaxPacketSize: 64 Bytes max  */
    0x00,
    0x10,	/* bInterval: Polling Interval (16 ms) */
    /* 41 */

    
    /*KeyBoard:->EnpAddr 3-4*/
    /************** Descriptor of KeyBoard interface ****************/
    /* 41 */
    0x09,         /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,/* bDescriptorType: Interface descriptor type */
    0x01,         /* bInterfaceNumber: Number of Interface */
    0x00,         /* bAlternateSetting: Alternate setting */
    0x02,         /* bNumEndpoints */
    0x03,         /* bInterfaceClass: HID */
    0x00,         /* bInterfaceSubClass : 1=BOOT, 0=no boot */
    0x01,         /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
    5,            /* iInterface: Index of string descriptor */
    /******************** Descriptor of KeyBoard HID ********************/
    /* 50 */
    0x09,         /* bLength: HID Descriptor size */
    HID_DESCRIPTOR_TYPE, /* bDescriptorType: HID */
    0x10,         /* bcdHID: HID Class Spec release number */
    0x01,
    0x00,         /* bCountryCode: Hardware target country */
    0x01,         /* bNumDescriptors: Number of HID class descriptors to follow */
    0x22,         /* bDescriptorType */
    KEYBOARD_SIZ_REPORT_DESC,/* wItemLength: Total length of Report descriptor */
    0x00,
    /******************** Descriptor of Custom HID endpoints ******************/
    /* 59 */
    0x07,          /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: */

    0x82,          /* bEndpointAddress: Endpoint Address (IN) */               
    0x03,          /* bmAttributes: Interrupt endpoint */
    0x08,          /* wMaxPacketSize: 64 Bytes max */
    0x00,
    0x20,          /* bInterval: Polling Interval (21 ms) */
    /* 66 */
    	
    0x07,	/* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,	/* bDescriptorType: */
		/*	Endpoint descriptor type */
    0x02,	/* bEndpointAddress: */
		/*	Endpoint Address (OUT) */
    0x03,	/* bmAttributes: Interrupt endpoint */
    0x01,	/* wMaxPacketSize: 64 Bytes max  */
    0x00,
    0x20,	/* bInterval: Polling Interval (32 ms) */
    /* 73 */
}
  ; /* CustomHID_ConfigDescriptor */

const uint8_t KeyBoard_ReportDescriptor[KEYBOARD_SIZ_REPORT_DESC] =
  {
    0x05, 0x01,         /*Usage Page(Generic Desktop)*/
    
    0x09, 0x06,         /*Usage(KeyBoard)*/
    
    0xA1, 0x01,         /*Collection(Logical)*/
    
    0x05, 0x07,         /*Usage(KeyBoard)*/
    
    /* 8 */
    0x19, 0xe0,         /*USAGE_MINIMUM (Keyboard LeftControl)*/
    
    0x29, 0xe7,         /*USAGE_MAXIMUM (Keyboard Right GUI)*/
    
    0x15, 0x00,         /*LOGICAL_MINIMUM (0)*/
    
    0x25, 0x01,         /*LOGICAL_MAXIMUM (1)/
    
    / * 16 */
    0x95, 0x08,         /*REPORT_COUNT(8)*/
    
    0x75, 0x01,         /*REPORT_SIZE(1)*/
    
    0x81, 0x02,         /*INPUT (Data,Var,Abs)*/
    
    0x95, 0x01,         /*REPORT_COUNT(1)*/
    
    /* 24 */
    0x75, 0x08,         /*REPORT_SIZE(8)*/
    
    0x81, 0x03,         /*INPUT (Cnst,Var,Abs)*/
    
    0x95, 0x06,         /*REPORT_COUNT(6)*/
    
    0x75, 0x08,         /*REPORT_SIZE(8)*/
    
    /* 32 */
    0x15, 0x00,         /*LOGICAL_MINIMUM (0)*/
    
    0x25, 0xff,         /*LOGICAL_MAXIMUM (255)*/
    
    0x05, 0x07,         /*Usage(KeyBoard)*/
    
    0x19, 0x00,         /*USAGE_MINIMUM(0)*/
    
    /* 40 */
    0x29, 0x65,         /*USAGE_MAXIMUM(101)*/
    
    0x81, 0x00,         /*INPUT(Data,Ary,Abs)*/
   
    0x25, 0x01,         /*LOGICAL_MAXIMUM (1)*/
    
    0x95, 0x05,         /*Report Count(5)*/
    
    /* 48 */
    0x75, 0x01,         /*REPORT_SIZE(1)*/
    
    0x05, 0x08,         /*USAGE_PAGE (LEDs)*/
    
    0x19, 0x01,         //USAGE_MINIMUM (Num Lock)
    
    0x29, 0x05,         //USAGE_MAXIMUM (Kana)
    
    /* 56 */
    0x91, 0x02,         //OUTPUT (Data,Var,Abs)
    
    0x95, 0x01,         //Report Count(1)
    
    0x75, 0x03,         //REPORT_SIZE(3)
    
    0x91, 0x03,         //OUTPUT (Cnst,Var,Abs)
    
    /* 64 */
    0xc0
}; /* KeyBoard_ReportDescriptor */

const uint8_t CustomHID_ReportDescriptor[CUSTOMHID_SIZ_REPORT_DESC] =
  {   
    0x05, 0x8c,                 /* USAGE_PAGE (ST Page) */ 
    0x09, 0x01,                 /* USAGE (Demo Kit)               */    
    0xa1, 0x01,                 /* COLLECTION (Application)       */            
    /* 6 */
    
    0x09, 0x03,                 /* USAGE ID - Vendor defined      */
    0x15, 0x00,                 /*     LOGICAL_MINIMUM (0)        */          
    0x26, 0x00, 0xFF,           /*     LOGICAL_MAXIMUM (255)      */           
    0x75, 0x08,                 /*     REPORT_SIZE (8)            */        
    0x95, CustomHID_RXMAXLEN,   /*     REPORT_COUNT (CustomHID_RXMAXLEN)*/       
    0x81, 0x02,                 /*     INTPUT (Data,Var,Abs)  */
    /* 19 */
    
    0x09, 0x04,                 /* USAGE ID - Vendor defined      */
    0x15, 0x00,                 /*     LOGICAL_MINIMUM (0)        */          
    0x26, 0x00, 0xFF,           /*     LOGICAL_MAXIMUM (255)      */           
    0x75, 0x08,                 /*     REPORT_SIZE (8)            */        
    0x95, CustomHID_TXMAXLEN,  /*     REPORT_COUNT (CustomHID_TXMAXLEN)*/       
    0x91, 0x02,                /*     OUTPUT (Data,Var,Abs)   */
    /* 19 */

    0xc0 	               /*     END_COLLECTION	             */
}; /* CustomHID_ReportDescriptor */

/* USB String Descriptors (optional) */
const uint8_t Composite_StringLangID[Composite_SIZ_STRING_LANGID] =
  {
    Composite_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04
  }
  ; /* LangID = 0x0409: U.S. English */

const uint8_t Composite_StringVendor[Composite_SIZ_STRING_VENDOR] =
  {
    Composite_SIZ_STRING_VENDOR, /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
    'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
    'c', 0, 's', 0
  };

const uint8_t Composite_StringProduct[Composite_SIZ_STRING_PRODUCT] =
  {
    Composite_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, ' ', 0, 'C', 0,
    'o', 0, 'm', 0, 'p', 0, 'o', 0, 's', 0, 'i', 0, 't', 0,
    'e', 0,' ',0, 'M', 0, 'S', 0, 'C', 0, '+', 0, 'H', 0, 'I', 0, 'D', 0
  };
uint8_t Composite_StringSerial[Composite_SIZ_STRING_SERIAL] =
  {
    Composite_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0,'3', 0,'2', 0
  };

/*Mouse*/
const unsigned char CustomHID_StringMouse[Composite_SIZ_STRING_MOUSE]={
  0x0C,0x03,0x4D,0x00,0x6F,0x00,
  0x75,0x00,0x73,0x00,0x65,0x00
};

/*KeyBoard*/
const unsigned char CustomHID_StringKeyBoard[Composite_SIZ_STRING_KEYBOARD]={
  0x12,0x03,0x4B,0x00,0x65,0x00,
  0x79,0x00,0x42,0x00,0x6F,0x00,
  0x61,0x00,0x72,0x00,0x64,0x00
};

/*RFID Reader */
const unsigned char CustomHID_StringHIDTxRxDev[Composite_SIZ_STRING_HDIDEV]=
{
  0x18,0x03,0x52,0x00,0x46,0x00,
  0x49,0x00,0x44,0x00,0x20,0x00,
  0x52,0x00,0x65,0x00,0x61,0x00,
  0x64,0x00,0x65,0x00,0x72,0x00
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

