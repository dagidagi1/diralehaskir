#define _CRT_SECURE_NO_WARNINGS
#include "structs.h"
#include "diralehaskir.h"
//#include <datetimeapi.h>// or another maybe??? 
using namespace std;

int landlordSignIn(int size, landlord** landlordArr) {//returns true if login successful
	string tempId, tempPass;
	cout << "***LANDLORD - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get id input
	cout << "ID must be exactly " << MAX_ID << " digits, numbers only." << endl;
	cout << "Please enter your ID:" << endl;
	cin >> tempId;
	//check length and input correctness
	if (tempId.length() != MAX_ID) {
		cout << "No such ID..." << endl;
		return NOT_FOUND;
	}
	//find index for landlord in array by id- assuming no two identical id's
	int index = findLandlordById(size, *landlordArr, tempId);
	if (index == NOT_FOUND) {//landlord not found
		cout << "No such ID..." << endl;
		return NOT_FOUND;
	}

	//get password
	cout << "Password must be minimum: " << MIN_PASSWORD
		<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
		<< "Can contain any characters you wish except 'enter'." << endl;
	cout << "Please enter your password:" << endl;
	cin >> tempPass;
	//check length and input correctness
	if (tempPass.length() > MAX_PASSWORD || tempPass.length() < MIN_PASSWORD) {
		cout << "Incorrect password...try again." << endl;
		return NOT_FOUND;
	}
	if (tempPass != landlordArr[index]->password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return NOT_FOUND;
	}
	return index;
}

bool isStringAllDig(string str) {//check id the string is all digits
	for (int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))//if false
			return false;
	}
	return true;
}
//-------------find landlord by id
int findLandlordById(int size, const landlord* const landlordArr, string id) {
	int i = 0;
	for (; i < size; ++i) {
		if (landlordArr[i].id == id)//if equal
			return i;
	}
	return NOT_FOUND;
}

int travelerSignIn(int size, traveler** travelerArr) {
	string tempName, tempPass;
	cout << "***TRAVELER - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get name input
	cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
	cout << "Please enter your full name:" << endl;
	//cin >> tempName;
	cin.ignore();
	getline(cin, tempName);
	//check length and input correctness
	if (tempName.length() > MAX_NAME) {
		cout << "No such user..." << endl;
		return NOT_FOUND;
	}
	//find index for traveler in array by name- assuming no two identical names
	int index = findTravelerByName(size, *travelerArr, tempName);
	if (index == NOT_FOUND) {//traveler not found
		cout << "No such user..." << endl;
		return NOT_FOUND;
	}

	//get password
	cout << "Password must be minimum: " << MIN_PASSWORD
		<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
		<< "Can contain any characters you wish except 'enter'." << endl;
	cout << "Please enter your password:" << endl;
	cin >> tempPass;
	//check length and input correctness
	if (tempPass.length() > MAX_PASSWORD || tempPass.length() < MIN_PASSWORD) {
		cout << "Incorrect password...try again." << endl;
		return NOT_FOUND;
	}
	if (tempPass != travelerArr[index]->password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return not NOT_FOUND;
	}
	return index;
}

//-------------find traveler by full name
int findTravelerByName(int size, const traveler* travelerArr, string name)
{
	int i = 0;
	for (; i < size; ++i) {
		if (travelerArr[i].fullName == name)//traveler found
			return i;
	}
	return NOT_FOUND;
}

//-------------sign up(after successful signup redirect to signin)-add new user to db
void landlordSignUp(int size, landlord* landlordArr) {

	bool flag = true;
	landlord tempL;
	string buffer;
	cout << "***LANDLORD - SIGN UP***" << endl << "Please enter details according to instrctions" << endl;
	//get name input
	do {
		cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:" << endl;
		cin.ignore();
		getline(cin, buffer);
		if (buffer.length() <= MAX_NAME && buffer.length() > 0) {
			if (isStringAllLetters(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.fullName = buffer;

	//get phone number
	do {
		cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_PHONE) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.phoneNumber = buffer;

	//get password
	do {
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_PASSWORD && buffer.length() >= MIN_PASSWORD) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.password = buffer;

	//get id
	do {
		cout << "PhoneNumber must be exactly " << MAX_ID << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_ID) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.id = buffer;

	//get mail
	int choice = 0;
	do {
		cout << "Choose your mail type:" << endl
			<< "1. " << GMAIL << endl
			<< "2. " << WALLA << endl;
		cin >> choice;
		cout << "Your mail prefix can be maximum: " << MAX_EMAIL << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your email:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_EMAIL && buffer.length() > 0) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	if (choice == 1)
		tempL.email = buffer + GMAIL;
	else
		tempL.email = buffer + WALLA;

}//return value???

bool isStringAllLetters(string str)
{
	for (int i = 0; i < str.length(); ++i)
		if (!isalpha(str[i]) && str[i] != ' ')
			return false;
	return true;
}
void travelerSignUp(traveler* travelerArr, int size)
{
	bool flag = true;
	traveler tempT;
	string buffer;
	cout << "***TRAVELER - SIGN UP***" << endl << "Please enter details according to instrctions" << endl;
	//get name input
	do {
		cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:" << endl;
		cin.ignore();
		getline(cin, buffer);
		if (buffer.length() <= MAX_NAME && buffer.length() > 0) {
			if (isStringAllLetters(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.fullName = buffer;

	//get phone number
	do {
		cout << "Phone number must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phone number:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_PHONE) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.phoneNumber = buffer;

	//get password
	do {
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_PASSWORD && buffer.length() >= MIN_PASSWORD) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.password = buffer;
}
string ValidLocation()
{
	//Location format <city>, <street> st.
	string location = "";
	string tmp;
	char answer;
	cout << "Please enter city: ";
	cin.ignore();
	getline(cin, tmp);
	location += tmp;
	cout << "Do you want to enter address?" << endl << "'y' for yes, else for no: ";
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Please enter street name: ";
		cin.ignore();
		getline(cin, tmp);
		location += ", " + tmp + " st.";
	}
	else location += ".";
	return location;
}

//-------------check correctnes of input for new/edit ad
int ValidInput(int min, int max)
{
	//gets int as input from user: (min <= USER_INPUT <= max)
	//if wrong gets another one and prints error message.
	int num;
	cin >> num;
	while (num < min || num >max)
	{
		cout << "Wrong number!\n Must be: " << min << " <= YOUR_NUMBER <= " << max << ": " << endl;
		cin >> num;
	}
	return num;
}

bool ValidInput(char truevaluechar)
{//returns true for 'truevaluechar' else return false.
	char tmp;
	cin >> tmp;
	if (tmp == truevaluechar) return true;
	else return false;
}

bool ValidInput(int num, int min, int max)//--------------------------------------------
{
	//gets int as input from user: (min <= USER_INPUT <= max)
	if (num < min || num >max) {
		cout << "Wrong input!\n Must be: " << min << " <= YOUR_INPUT <= " << max << ". " << endl;
		return false;
	}
	return true;
}

//-------------get amenities
amenities amenitiesCtor()
{//User input for each amenity.
	amenities obj;
	cout << "enter 'y' for yes, other for no" << endl;
	cout << AMENITIES_NAMES[0] << ": ";
	obj.disabledAccess = ValidInput('y');
	cout << AMENITIES_NAMES[1] << ": ";
	obj.wifi = ValidInput('y');
	cout << AMENITIES_NAMES[2] << ": ";
	obj.kitchen = ValidInput('y');
	cout << AMENITIES_NAMES[3] << ": ";
	obj.tv = ValidInput('y');
	cout << AMENITIES_NAMES[4] << ": ";
	obj.balcony = ValidInput('y');
	cout << AMENITIES_NAMES[5] << ": ";
	obj.washingMachine = ValidInput('y');
	cout << AMENITIES_NAMES[6] << ": ";
	obj.airConditioning = ValidInput('y');
	cout << AMENITIES_NAMES[7] << ": ";
	obj.swimmingPool = ValidInput('y');
	cout << AMENITIES_NAMES[8] << ": ";
	obj.parkingLot = ValidInput('y');
	return obj;
}
void RealocateAdsPointer(ad* adsArr, int& adsize)
{
	//reallocates the pointer and changes the size:
	ad* tmp;
	tmp = new ad[adsize + 1];
	for (int i = 0; i < adsize; i++)
		tmp[i] = adsArr[i];
	adsize++;
	delete[] adsArr;
	adsArr = tmp;
}
void PrintAd(ad obj)
{
	cout << ADSBREAK << endl;
	cout << "Location: " << obj.location << endl;
	cout << "Ad description: " << obj.description << endl;
	cout << "Price before discount: " << obj.price << endl;
	cout << "Price after discount:  " << obj.price - obj.discount << endl;
	cout << "Discount: " << "-" << obj.discount << "NIS" << endl;
	cout << "Number of people: " << obj.numOfPeople << endl;
	cout << "Number of rooms: " << obj.numOfRooms << endl;
	cout << "Number of beds: " << obj.numOfBeds << endl;
	cout << "Atraction: " << obj.attraction << endl;
	PrintAmenities(obj.ameNities);
}
//-------------edit ad
void EditAdMenu(ad* ad)
{
	int choose = 1;
	while (choose)
	{
		system("CLS");
		cout << "EDIT AD MENU \nYour ad:" << endl;
		PrintAd(*ad);
		cout << ADSBREAK << endl;
		cout << "What do you want to edit?" << endl;
		cout << "1) Change avilability (now: " << ad->available << ")." << endl
			<< "2) Change Description." << endl
			<< "3) Change Price." << endl
			<< "4) Change Discount." << endl
			<< "5) Change num of people." << endl
			<< "6) Change num of rooms." << endl
			<< "7) Change num of beds." << endl
			<< "8) Edit amenities." << endl
			<< "9) Change attractions." << endl
			<< "0) Back to previous menu." << endl
			<< "Please enter your choice: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			ad->available = !ad->available;
			break;
		case 2:
			cout << "Enter new description:";
			cin.ignore();
			getline(cin, ad->description);
			break;
		case 3:
			cout << "Enter new price: ";
			ad->price = ValidInput(ZERO, INT_MAX);
			break;
		case 4:
			cout << "Enter new discount: ";
			ad->discount = ValidInput(ZERO, 100);
			break;
		case 5:
			cout << "Number of people(up to 30): ";
			ad->numOfPeople = ValidInput(1, 30);
			break;
		case 6:
			cout << "Number of rooms(up to 15): ";
			ad->numOfRooms = ValidInput(1, 15);
			break;
		case 7:
			cout << "Number of beds(up to 30): ";
			ad->numOfBeds = ValidInput(1, 30);
			break;
		case 8:
			cout << "Select amenities: ";
			ad->ameNities = amenitiesCtor();
			break;
		case 9:
			cout << "Enter a new attraction:";
			cin.ignore();
			getline(cin, ad->attraction);
			break;
		case 0:
			return;
			break;
		default:
			cout << "You entered a wrong choice!!\n Try again: ";
			cin >> choose;
			break;
		}
	}
}
void DeleteAd(ad* adsArr, int& adsize, int index)
{
	//delete the ad at [index] location.
	if (!adsize) cout << "No ads to delete!!!" << endl;
	else
	{
		ad* tmp = new ad[adsize - 1];
		for (int i = 0, j = 0; i < adsize - 1; j++, i++)
		{
			if (i == index) j++;
			tmp[i] = adsArr[j];
		}
		delete[] adsArr;
		adsArr = tmp;
		adsize--;
	}

}
ad NewAd()
{//User input for new ad.
	ad newAd;
	newAd.available = true;
	cout << "New ad: " << endl;
	cout << "Ad description: ";
	getline(cin, newAd.description);
	cout << "Price: ";
	newAd.price = ValidInput(ZERO, INT_MAX);
	cout << "Discount(0 ~ Price): ";
	newAd.discount = ValidInput(ZERO, newAd.price);
	newAd.location = ValidLocation();
	cout << "Number of people(up to 30): ";
	newAd.numOfPeople = ValidInput(1, 30);
	cout << "Number of rooms(up to 15): ";
	newAd.numOfRooms = ValidInput(1, 15);
	cout << "Number of beds(up to 30): ";
	newAd.numOfBeds = ValidInput(1, 30);
	cout << "Atraction: ";
	cin.ignore();
	getline(cin, newAd.attraction);
	cout << "Select amenities: ";
	newAd.ameNities = amenitiesCtor();
	newAd.rating = 5;
	return newAd;
}
void PrintAmenities(amenities obj)
{
	string str = "Amenities:";
	if (obj.disabledAccess) str += AMENITIES_NAMES[0] + ", ";
	if (obj.wifi) str += AMENITIES_NAMES[1] + ", ";
	if (obj.kitchen) str += AMENITIES_NAMES[2] + ", ";
	if (obj.tv) str += AMENITIES_NAMES[3] + ", ";
	if (obj.balcony) str += AMENITIES_NAMES[4] + ", ";
	if (obj.washingMachine) str += AMENITIES_NAMES[5] + ", ";
	if (obj.airConditioning) str += AMENITIES_NAMES[6] + ", ";
	if (obj.swimmingPool) str += AMENITIES_NAMES[7] + ", ";
	if (obj.parkingLot) str += AMENITIES_NAMES[8] + ", ";
	str[str.length() - 2] = '.';
	cout << str << endl;
}
void LandlordsMenu(landlord ll)
{
	int choise = 1;
	cout << "LANDLORD MENU:" << endl;
	cout << "Total profit: " << ll.sumOfDeals << endl;
	if (ll.adSize)
		for (int i = 0; i < ll.adSize; i++)
		{
			cout << ADSBREAK << endl << "\tAd no: " << i + 1 << endl;
			PrintAd(ll.properties[i]);
		}
	cout << ADSBREAK << endl;
	int input;
	while (choise != 4)
	{
		cout << "Please select an option:" << endl
			<< "1) edit an ad." << endl
			<< "2) add new ad." << endl
			<< "3) delete an ad." << endl
			<< "4) Exit." << endl
			<< "enter your choice: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Please enter ad number: ";
			input = ValidInput(1, ll.adSize) - 1;
			EditAdMenu(&ll.properties[input]);
			break;
		case 2:
			RealocateAdsPointer(ll.properties, ll.adSize);
			ll.properties[ll.adSize - 1] = NewAd();
			break;
		case 3:
			cout << "Please enter ad number: ";
			input = ValidInput(1, ll.adSize) - 1;
			DeleteAd(ll.properties, ll.adSize, input);
			break;
		case 4:
			//exit
			system("CLS");
			cout << "Good bye!!" << endl;
			break;
		default:
			cout << "Wrong choice!!\nTry again!\n ";
			break;
		}
	}


}
void RealloctravelersArr(traveler** arr, int& size)
{
	size++;
	traveler** tmp = new traveler * [size];
	if (!tmp) cout << "Memory allocate fail!" << endl;
	for (int i = 0; i < size - 1; i++) tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}
void ReallocLandlordsArr(landlord** arr, int size)
{
	landlord** tmp = new landlord * [size + 1];
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	size++;
	delete[] arr;
	arr = tmp;
}

void Register(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	system("CLS");
	int choise = 1;
	bool flag = true;
	while (choise != 3 && flag)
	{
		cout << "Register:" << endl
			<< "1)Landlord." << endl
			<< "2)Traveler." << endl
			<< "3)Return to previous menu." << endl
			<< "Please enter your choise: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			RegisterLandlord(landlordsArr, landlordSize, travelersArr, travelersSize);
			flag = false;
			//update db
			system("CLS");
			break;
		case 2:
			RegisterTraveler(travelersArr, travelersSize);
			flag = false;
			//update db
			//RealloctravelersArr(travelersArr, travelersSize);
			//cout << trv->phoneNumber;
			//travelersArr[travelersSize - 1] = NewTraveler();
			system("CLS");
			cout << "Traveler added successfuly!" << endl;
			break;
		case 3:
			system("CLS");
			break;
		default:
			cout << "Wrong choise!!\nTry again: ";
			break;
		}
	}
}

void MainPage(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	//system("CLS");
	int landlord_index = NOT_FOUND;
	int traveler_index = NOT_FOUND;
	int choise = 0;
	while (choise != 4)
	{
		cout << "main menu:" << endl//need to be changed! add beutiful header.
			<< "1) Log in as traveler." << endl
			<< "2) Log in as landlord." << endl
			<< "3) Register." << endl
			<< "4) Exit." << endl
			<< "Please enter your choise:";
		cin >> choise;
		switch (choise)
		{
		case 1:
			traveler_index = travelerSignIn(travelersSize, travelersArr);
			cout << traveler_index;
			break;
		case 2:
			landlord_index = landlordSignIn(landlordSize, landlordsArr);// -  change to duble pointer.
			cout << landlord_index;
			break;
		case 3:
			Register(landlordsArr, landlordSize, travelersArr, travelersSize);
			break;
		case 4:
			cout << "Good bye!";
			break;
		default:
			cout << "Wrong choise!!\nTry again: ";
			break;
		}

	}
}


void PrintLandlordsAds(landlord ll)
{
	if (!ll.adSize)
	{
		cout << "No ads!" << endl;
		return;
	}
	for (int i = 0; i = ll.adSize; i++)
	{
		PrintAd(ll.properties[i]);
	}
	cout << ADSBREAK << endl;
}

string NameInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "Name must be up to  " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:";
		cin.ignore();
		getline(cin, buffer);
		if (!(buffer.length() <= MAX_NAME && buffer.length() > 0)) flag = true;
		if (!isStringAllLetters(buffer)) flag = true;
		if (flag) cout << "Incorrect input, try again." << endl;
	} while (flag);
	return buffer;
}
string PhoneInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:";
		getline(cin, buffer);
		if (buffer.length() != MAX_PHONE) flag = true;
		if (!isStringAllDig(buffer)) flag = true;
		if (flag) cout << "Incorrect length, try again." << endl;
	} while (flag);
	return buffer;
}
string PasswordInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:";
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() < MIN_PASSWORD || buffer.length() > MAX_PASSWORD) flag = true;
		if (flag) cout << "Incorrect length, try again." << endl;
	} while (flag);
	return buffer;
}


traveler* NewTraveler()
{
	traveler* trv = new traveler;
	trv->fullName = NameInput();
	trv->phoneNumber = PhoneInput();
	trv->password = PasswordInput();
	cout << "NewTraveler: " << trv->fullName << endl;
	cout << "NewTraveler: " << trv->phoneNumber << endl;
	cout << "NewTraveler: " << trv->password << endl;
	return trv;
}
void RegisterTraveler(traveler** travelersArr, int& size)
{
	size++;
	traveler** tmp = new traveler * [size];
	if (!tmp) cout << "Memory allocate fail!" << endl;
	for (int i = 0; i < size - 1; i++) tmp[i] = travelersArr[i];
	travelersArr = tmp;
	//cout << trv->phoneNumber;
	travelersArr[size - 1] = NewTraveler();
	//cout <<endl<<"dd: "<< trv->password;
	cout << travelersArr[size - 1]->phoneNumber;
}

string ValidId()
{
	string id;
	bool has_only_digits = false;
	while (!has_only_digits)
	{
		cout << "Please enter id(9 digits): ";
		cin >> id;
		has_only_digits = true;
		for (int i = 0; i < id.length(); i++)
			if (!isdigit(id[i])) has_only_digits = false;
		if (!has_only_digits) cout << "Wrong id! Please try again!" << endl;
	}
	return id;
}
string ValidEmail()
{
	/// gets a valid email form from user.
	string email;
	bool at = false, dot = false;
	while (!at || !dot)
	{
		at = false;
		dot = false;
		cout << "Please enter email: ";
		cin >> email;
		for (int i = 0; i < email.length(); i++)
		{
			if (email[i] == '@') at = true;
			if (at && email[i] == '.') dot = true;
		}
		if (!at || !dot) cout << "Wrong email! Please try again!" << endl;
	}
	return email;
}
void RegisterLandlord(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	RegisterTraveler(travelersArr, travelersSize);
	landlord* newLandlord = new landlord;
	newLandlord->fullName = travelersArr[travelersSize - 1]->fullName;
	newLandlord->phoneNumber = travelersArr[travelersSize - 1]->phoneNumber;
	newLandlord->password = travelersArr[travelersSize - 1]->password;
	newLandlord->id = ValidId();
	newLandlord->email = ValidEmail();
	newLandlord->sumOfDeals = 0;
	newLandlord->adSize = 0;
	ReallocLandlordsArr(landlordsArr, landlordSize);
	landlordsArr[landlordSize - 1] = newLandlord;
}

int main()
{
	landlord** landlord_arr = NULL;
	int landlord_arr_size = 0;
	traveler** travelers_arr = NULL;
	int travelers_arr_size = 0;
	MainPage(landlord_arr, landlord_arr_size, travelers_arr, travelers_arr_size);
	return 0;
}

