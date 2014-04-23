/*
This file is part of the GSM3 communications library for Arduino
-- Multi-transport communications platform
-- Fully asynchronous
-- Includes code for the Arduino-Telefonica GSM/GPRS Shield V1
-- Voice calls
-- SMS
-- TCP/IP connections
-- HTTP basic clients

This library has been developed by Telefónica Digital - PDI -
- Physical Internet Lab, as part as its collaboration with
Arduino and the Open Hardware Community. 

September-December 2012
Modified 20 April 2014 by Android Lin for 86Duino

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

The latest version of this library can always be found at
https://github.com/BlueVia/Official-Arduino
*/
#ifndef _GSM3SIMPLIFIERFILE_
#define _GSM3SIMPLIFIERFILE_

// This file simplifies the use of the GSM3 library
// First we include everything. 

#include <GSM3CB.h>
#include <GSM3MCM.h>
#include <GSM3MCS.h>
#include <GSM3MNR.h>
#include <GSM3MSS.h>
#include <GSM3SAP.h>
#include <GSM3SBM.h>
#include <GSM3SCP.h>
#include <GSM3SDNP.h>
#include <GSM3SMV.h>
#include <GSM3SPM.h>
#include <GSM3SSN.h>
#include <GSM3SMSS.h>
#include <GSM3VCS.h>

#define GSM GSM3ShieldV1AccessProvider
#define GPRS GSM3ShieldV1DataNetworkProvider
#define GSMClient GSM3MobileClientService
#define GSMServer GSM3MobileServerService
#define GSMVoiceCall GSM3VoiceCallService
#define GSM_SMS GSM3SMSService

#define GSMPIN GSM3ShieldV1PinManagement
#define GSMModem GSM3ShieldV1ModemVerification
#define GSMCell GSM3CellManagement
#define GSMBand GSM3ShieldV1BandManagement
#define GSMScanner GSM3ShieldV1ScanNetworks

extern void useHardwareSerial(int hwcom=1, int combaud=9600);

#endif