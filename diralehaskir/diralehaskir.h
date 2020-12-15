#ifndef DIRALEHASKIR_H
#define DIRALEHASKIR_H
#include <iostream>
#include <stdlib.h>
//#include <cstdlib>
#include <stdio.h>
//#include <cstring>
#include <string>
//#include <string.h>
#include <fstream>
#include <ctime>
#include <ctype.h>
using namespace std;

#define ADSBREAK "========================================="
#define ZERO 0
#define MAX_EMAIL 8 //רק לקידומת
#define MAX_ID 9
#define MAX_PHONE 10
#define MAX_NAME 15 //enough???
#define MAX_PASSWORD 10 //less???
#define MIN_PASSWORD 4
#define BUFFER 20
#define AMENITIES 9
#define NOT_FOUND -1
#define MINinput 1
#define MAX_DAY 31
#define MAX_MONTH 12
#define CURRENT_YEAR 2020
#define MAX_YEAR 2030

const string AMENITIES_NAMES[AMENITIES] = { "disabledAccess", "wifi", "kitchen", "tv", "balcony", "washingMachine", "airConditioning", "swimmingPool", "parkingLot" };
//Landlord arr + size
landlord* landlord_arr = NULL;
int landlord_arr_size = 0;
//Traveler arr + size
traveler* travelers_arr = NULL;
int travelers_arr_size = 0;

//Register:
void Register();
traveler NewTraveler();
void RegisterTraveler();
void RegisterLandlord();
//Sing-in funcs:
int landlordSignIn();
int findLandlordById(string id);
int travelerSignIn();
int findTravelerByName(string name);
//input validation:
bool isStringAllDig(string str);
bool isStringAllLetters(string str);
string ValidLocation();
int ValidInput(int min, int max);
bool ValidInput(char truevaluechar);
bool ValidInput(int num, int min, int max);
string NameInput();
string PhoneInput();
string PasswordInput();
string ValidId();
string ValidEmail();
amenities amenitiesCtor();
//Menus:
void MainPage();
void LandlordsLoginMenu(int ll_index, int trv_index);
void LandlordsMenu(int index);
void PrintAd(ad obj);
void EditAdMenu(int ll_index, int ad_index);
//Ads manipulations:
void DeleteAd(int landlord_index, int ad_index);
ad NewAd();
//Realloc:
void RealloctravelersArr();
void ReallocLandlordsArr();
void RealocateAdsPointer(int landlord_index);
//Output:
void PrintLandlordsAds(landlord ll);
void PrintAmenities(amenities obj);




#endif // !DIRALEHASKIR_H
