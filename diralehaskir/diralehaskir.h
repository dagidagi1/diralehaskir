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

#define ADSBREAK "========================================="
#define ZERO 0
#define MAX_EMAIL 8 //רק לקידומת
#define GMAIL "@gmail.com"
#define WALLA "@walla.co.il"
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

landlord* landlord_arr = NULL;
int landlord_arr_size = 0;
traveler* travelers_arr = NULL;
int travelers_arr_size = 0;
using namespace std;

int landlordSignIn();
bool isStringAllDig(string str);
int findLandlordById(string id);
int travelerSignIn();
int findTravelerByName(string name);
void landlordSignUp(int size, landlord* landlordArr);
bool isStringAllLetters(string str);
void travelerSignUp(traveler* travelerArr, int size);
string ValidLocation();
int ValidInput(int min, int max);
bool ValidInput(char truevaluechar);
bool ValidInput(int num, int min, int max);
amenities amenitiesCtor();
void RealocateAdsPointer(int landlord_index);
void PrintAd(ad obj);
void EditAdMenu(ad* ad);
void DeleteAd(int landlord_index, int ad_index);
ad NewAd();
void PrintAmenities(amenities obj);
void LandlordsMenu(int index);
void RealloctravelersArr();
void ReallocLandlordsArr();
void Register();
void MainPage();
void PrintLandlordsAds(landlord ll);
string NameInput();
string PhoneInput();
string PasswordInput();
void NewTraveler(traveler&);
void RegisterTraveler();
string ValidId();
string ValidEmail();
void RegisterLandlord();





#endif // !DIRALEHASKIR_H
