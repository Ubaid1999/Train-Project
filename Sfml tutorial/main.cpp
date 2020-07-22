#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>

using namespace std;

void Print_application(string str ,int size)  // prints on Application (Graphics)
{
	sf::Text txt;
	sf::Font font;
	font.loadFromFile("geomentos.ttf");

	txt.setFont(font);
	txt.setString(str);
	txt.setStyle(sf::Text::Regular);
	txt.setCharacterSize(size);
	
	txt.setFillColor(sf::Color::Blue);

	sf::RenderWindow wind(sf::VideoMode(550, 550), "Print", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape background(sf::Vector2f(550, 550));   
	background.setPosition(0.0, 0.0);
	while (wind.isOpen())
	{


		sf::Event evnt;
		while (wind.pollEvent(evnt) == true)   
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:		//close ur application
				wind.close();
				break;

			case sf::Event::KeyPressed:
				wind.close();

			case sf::Event::Resized:
				sf::FloatRect visiblearea(0, 0, evnt.size.width, evnt.size.height);
				background.setScale(sf::Vector2f(1000, 1000));
				wind.setView(sf::View(visiblearea));
			}
		}
		wind.draw(background);
		wind.draw(txt);
		wind.display();
	}
}

string Input_application(string quest) // takes input from user 
{

	sf::RenderWindow window(sf::VideoMode(650,150), "Input", sf::Style::None);
	window.setPosition(sf::Vector2i(297, 469));
	sf::String input;

	sf::Font font;
	font.loadFromFile("geomentos.ttf");

	sf::Text Question;
	Question.setFont(font);
	Question.setStyle(sf::Text::Regular);
	Question.setCharacterSize(20);
	Question.setFillColor(sf::Color::White);
	Question.setString(quest);

	sf::Text playerinput;
	playerinput.setPosition(sf::Vector2f(10, 50));
	playerinput.setFont(font);
	playerinput.setStyle(sf::Text::Regular);
	playerinput.setCharacterSize(20);
	playerinput.setFillColor(sf::Color::White);


	while (window.isOpen())
	{
		sf::Event evnt3;
		while (window.pollEvent(evnt3) == true)
		{
			switch (evnt3.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:
				if (evnt3.text.unicode < 128)
				{
					input += evnt3.text.unicode;
					playerinput.setString(input);
				}
				if (evnt3.text.unicode == 13)
				{
					window.close();
				}
				if (evnt3.text.unicode == '\b' && input.getSize() != 1 )
				{
						input.erase(input.getSize() - 2, 2);
						playerinput.setString(input);

				}
			}
		}

		window.clear();
		window.draw(playerinput);
		window.draw(Question);
		window.display();

	}

	string s = input;

	return s;


}

class Person
{
private:

	char* Name;
	int Age;
	char Gender;

public:
	Person()
	{
		Name = NULL;
		/*cout << "Person() is called " << endl;*/
	}

	Person(char* name, int age, char gender)
	{
		this->Age = age;
		this->Gender = gender;

		strcpy_s(this->Name, 1000, name);
	}

	virtual void addinfo()
	{
		Name = new  char[1000];
		string name = Input_application("Enter Name of the passenger : ");
		int j = 0;
		for (j; j < name.length(); j++)
		{
			this->Name[j] = name[j];
		}
		this->Name[j] = '\0';

		string age = Input_application("Enter the age of the Passenger : \n");
		this->Age = stoi(age);

		string gender = Input_application("Enter Gender of the passenger : \n (M/m for Male F/f for Female)  ");
		this->Gender = gender[0];

	}

	virtual void printinfo(string &str)
	{
		str += Name;
		str += " is a ";


		if (Gender == 'm' || Gender == 'M')
		{
			
			str += "Male ";
		}
		else
		{
			
			str += "Female ";
		}
		str += "of Age ";
		str += to_string(Age);
		str += "\n";
	}

	virtual ~Person()
	{
		if (Name != NULL)
		{
			delete Name;
			Name = NULL;
		}
		/*cout << "~Person() is called" << endl;*/
	}
};

class Adult :public Person
{
private:

	char* occupation;
	char* Qualification;
	char* NIC;

public:
	Adult()
	{
		occupation = NULL;
		Qualification = NULL;
		NIC = NULL;

		/*cout << "Adult() is called " << endl;*/
	}

	Adult(char *occ, char *qua, char *Nic)
	{

		/*cout << "Adult() is called " << endl;*/

		strcpy_s(this->occupation, 1000, occ);

		strcpy_s(this->Qualification, 1000, qua);

		strcpy_s(this->NIC, 1000, Nic);

	}

	void addinfo() override // identifier 
	{
		Person::addinfo();

		string occup = Input_application("Enter passenger's Occupation : ");
		occupation = new char[1000];
		int i = 0;
		for (i; i < occup.length(); i++)
		{
			this->occupation[i] = occup[i];
		}
		this->occupation[i] = '\0';

		string Qua = Input_application("Enter passenger's Qualification : ");
		Qualification = new char[1000];
		int j = 0;
		for (j; j < Qua.length(); j++)
		{
			this->Qualification[j] = Qua[j];
		}
		this->Qualification[j] = '\0';

		string Nic = Input_application("Enter passenger's NIC : ");
		NIC = new char[1000];
		int k = 0;
		for (k; k < Nic.length(); k++)
		{
			this->NIC[k] = Nic[k];
		}
		this->NIC[k] = '\0';
		
	}

	void printinfo(string &str) 
	{
		Person::printinfo(str);

		str += "Passenger's Info : \n";

		
		str += "Occupation :  ";
		str += occupation;
		str += "\n";

		str += "Qualification : ";
		str += Qualification;
		str += "\n";

		str += "NIC  \t : ";
		str += NIC;
		str += "\n";
	}
	~Adult()
	{
		if (occupation != NULL)
		{
			delete occupation;
			occupation = NULL;
		}
		if (Qualification != NULL)
		{
			delete Qualification;
			Qualification = NULL;
		}
		if (NIC != NULL)
		{
			delete NIC;
			NIC = NULL;
		}
		/*cout << "~Adult() is called " << endl;*/
	}
};



class kid : public Person
{
private:

	char* B_form_no;

public:

	kid()
	{
		B_form_no = NULL;
		/*cout << "kid() is called " << endl;*/
	}

	kid(char *B_form)
	{

		strcpy_s(this->B_form_no, 1000, B_form);
	}

	void addinfo() override
	{
		Person::addinfo();

		string b_form = Input_application("Enter B form Number of the child : \n");
		B_form_no = new char[1000];
		
		int i = 0;
		for (i; i < b_form.length(); i++)
		{
			this->B_form_no[i] = b_form[i];
		}
		this->B_form_no[i] = '\0';
	}

	void printinfo(string &str) override
	{
		Person::printinfo(str);

		str += "B form Number of the passenger (child) :  ";
		str += B_form_no;
		str += "\n";
	}

	~kid()
	{
		if (B_form_no != NULL)
		{
			delete B_form_no;
			B_form_no = NULL;
		}

		/*cout << "~kid() is called " << endl;*/
	}

};



class Bogie
{
private:

	int Bogie_id;
	Bogie *next;
	Person *Adults[4];
	Person *kids[6];

	Person**Adults_delete = Adults; // two pointers to delete dynamic memory created outside class
	Person**kids_delete = kids;

	char* familyName;
	int check_kids;
	int check_Adults;

public:

	Bogie()
	{
		/*cout << "Bogie() is called " << endl;*/

		Bogie_id = NULL;
		next = NULL;
		familyName = NULL;
	}
	Bogie(int ID)
	{
		this->Bogie_id = ID;
	}

	Person ** Get_adult()
	{
		return Adults_delete;
	}

	Person ** Get_kids()
	{
		return kids_delete;
	}

	int get_checkKids()
	{
		return check_kids;
	}

	int get_checkAdults()
	{
		return check_Adults;
	}

	void Set_familyName(char * name)
	{
		familyName = new char[1000];
		strcpy_s(this->familyName, 1000, name);
	}

	char* Get_familyName()
	{
		return familyName;
	}

	void Set_nextBogie(Bogie* object)
	{
		this->next = object;
	}

	Bogie* Get_nextBogie()
	{
		return next;
	}

	void Addpassengers(Person* Adults[4], Person* Kids[6], int adultcheck, int kidscheck) // aggregation between Person (kid and adult) and Boogie
	{
		this->check_Adults = adultcheck;
		this->check_kids = kidscheck;

		for (int i = 0; i < 4; i++)
		{
			this->Adults[i] = Adults[i];
		}

		for (int j = 0; j < 6; j++)
		{
			this->kids[j] = Kids[j];
		}

	}

	void set_ID(int Id)
	{
		this->Bogie_id = Id;
	}

	int get_ID()
	{
		return Bogie_id;
	}

	void Print(string & str)
	{
		
		str += "Bogie's ID  :  ";
		str += to_string(this->Bogie_id);
		str += "\n";

		str += "Passengers info  : \n";


		str += "Adults  : \n";
		str += "\n";

		if (check_Adults == 0)
		{
			str += "no adults in the bogie \n\n";
		}
		for (int i = 0; i < check_Adults; i++)
		{
			str += "Adult # ";
			str += to_string(i + 1);
			str += "\n";

			Adults[i]->printinfo(str);
		}

		str += "\n Kids  : \n";
		str += "\n";

		if (check_kids == 0)
		{
			str += "no kids in the Bogie \n";
		}
		for (int j = 0; j < check_kids; j++)
		{
			str += "Kids # ";
			str += to_string(j + 1);
			str += "\n";
			kids[j]->printinfo(str);
		}

	}
	~Bogie()
	{
		if (next != NULL)
		{
			delete next;
			next = NULL;
		}
		if (familyName != NULL)
		{
			delete familyName;
			familyName = NULL;
		}

		if (Adults_delete != NULL)
		{
			Adults_delete = NULL;
		}

		if (kids_delete != NULL)
		{
			kids_delete = NULL;
		}

		/*cout << "~Bogie() is called" << endl;*/
	}

};

class train
{
private:

	Bogie * engine;

public:

	train()
	{
		/*cout << "train() is called " << endl;*/

		engine = NULL;
	}

	Bogie* Get_engine()
	{
		return engine;
	}

	void addbogie(int ID)	// adds boogie at the end of the train
	{
		Bogie * transverse = engine;
		if (engine == NULL)
		{
			engine = new Bogie(ID);
			engine->Set_nextBogie(NULL);
		}
		else
		{
			while (transverse->Get_nextBogie() != NULL)
			{
				transverse = transverse->Get_nextBogie();
			}
			Bogie *ptr = new Bogie(ID);
			ptr->Set_nextBogie(NULL);
			transverse->Set_nextBogie(ptr);
			ptr = NULL;
		}
	}

	bool SearchBogie(int ID)
	{
		Bogie *temp;

		temp = engine;

		int check = 0;

		while (temp != NULL) // if boogie is found or bogie doesnot exist
		{
			if (temp->get_ID() == ID)
			{
				return true;
			}
			else
			{
				temp = temp->Get_nextBogie();
			}
		}

		if (check == 0)
		{
			return false;
		}

	}

	void removeBogie(int ID)
	{
		if (SearchBogie(ID) == false)
		{
			Print_application("Boogie trains doesnot exist...\n Press any Key to return \n",20);
		}
		else
		{
			Bogie* temp;
			Bogie* prev;
			prev = engine; //transversal starting from engine 
			temp = prev->Get_nextBogie();

			if (prev->get_ID() == ID) // if the first bogie attached to engine is to be removed
			{
				engine = prev->Get_nextBogie();
				prev->Set_nextBogie(NULL);
				delete prev;
				prev = NULL;
				temp = NULL;
				Print_application(" Boogie is deleted...\n Press any Key to return \n",20);

			}
			else
			{
				while (temp->get_ID() != ID)
				{
					prev = temp;
					temp = temp->Get_nextBogie();
				}
				prev->Set_nextBogie(temp->Get_nextBogie());
				temp->Set_nextBogie(NULL);
				delete temp;
				temp = NULL;

				Print_application(" Boogie is deleted...\n Press any Key to return \n",20);
			}

		}
	}

	void printTrain()
	{
		Bogie* print;
		print = engine;

		string prnt;


		if (engine == NULL)
		{

			prnt += "No bogie is attached \n ";
		}
		else
		{
			prnt += "Engine \n";
			prnt += "| ";
			prnt += "|";
			prnt += "\n";
			while (print != NULL)
			{

				prnt += to_string(print->get_ID());
				prnt += "\n";
				print = print->Get_nextBogie();
				prnt += "| ";
				prnt += "|";
				prnt += "\n";
			}
		}

		Print_application(prnt,25);
		
	}

	int Reserve_Bogie(int ID, char* Fam_name, Person* Adults[4], Person* Kids[6], int check_adult, int check_kid) //the passed on ID would be available in train check already applied
	{
		Bogie *res;

		res = engine;



		while (res != NULL)
		{
			if (res->get_ID() == ID)
			{

				res->Set_familyName(Fam_name);
				res->Addpassengers(Adults, Kids, check_adult, check_kid);

				return 1;   // so it won't search further
			}
			else
			{
				res = res->Get_nextBogie();
			}
		}

	}

	int Print_BogieInfo(int ID)
	{
		Bogie *temp;

		temp = engine;

		string Bogie_prt;


		while (temp != NULL)
		{
			if (temp->get_ID() == ID)
			{
				if (temp->Get_familyName() == NULL)
				{
					
					Bogie_prt += "Boogie is Empty..\n";
					Print_application(Bogie_prt,20);
					return 1;
				}
				else
				{
					temp->Print(Bogie_prt);

					Print_application(Bogie_prt,11);

					return 1;
				}
			}
			else
			{
				temp = temp->Get_nextBogie();
			}
		}

		

	}


	bool Boogie_Status(int ID) // to check if boogie is already filled/reserved or not 
	{
		Bogie *check;

		check = engine;


		while (check != NULL)
		{
			if (check->get_ID() == ID)
			{
				if (check->Get_familyName() != NULL)
				{
					return true;    // the boogie is filled 
				}
				else
				{
					return false;  // boogie isn't filled
				}
			}
			else
			{
				check = check->Get_nextBogie();
			}
		}
	}


	~train()
	{
		delete engine;   // since composition is used train is responsible deleteing the boogie series
		engine = nullptr;
		/*cout << "~train() is called " << endl;*/
	}



};

int main()
{
	train t1;

	Person *Adults[4];
	Person * kids[6];
	int check_Adults; // to check adult number
	int check_kids;	  //to check kids number


	//Graphics 

	sf::RenderWindow window(sf::VideoMode(1119, 607), "Train", sf::Style::Close  | sf::Style::Resize );
	sf::RectangleShape background(sf::Vector2f(1119,607));   // vector 2F float vector 2I integer
	background.setPosition(0.0, 0.0);


	sf::Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("train.jpg");
	background.setTexture(&BackgroundTexture);
	BackgroundTexture.setSmooth(true);

	sf::Texture Option1Texture;
	Option1Texture.loadFromFile("1.png");
	Option1Texture.setSmooth(true);

	sf::Texture Option2Texture;
	Option2Texture.loadFromFile("2.png");
	Option2Texture.setSmooth(true);

	sf::Texture Option3Texture;
	Option3Texture.loadFromFile("3.png");
	Option3Texture.setSmooth(true);

	sf::Texture Option4Texture;
	Option4Texture.loadFromFile("4.png");
	Option4Texture.setSmooth(true);

	sf::Texture Option5Texture;
	Option5Texture.loadFromFile("5.png");
	Option5Texture.setSmooth(true);

	sf::Texture Option6Texture;
	Option6Texture.loadFromFile("6.png");
	Option6Texture.setSmooth(true);

	sf::Texture Option7Texture;
	Option7Texture.loadFromFile("7.png");
	Option7Texture.setSmooth(true);

	sf::Texture LogoTexture;
	LogoTexture.loadFromFile("logo.png");
	LogoTexture.setSmooth(true);

	sf::Texture LogoCyberEffect;
	LogoCyberEffect.loadFromFile("logo2.png");
	LogoCyberEffect.setSmooth(true);

	sf::Sprite Option2;    // remove boogie
	Option2.setPosition(-5, 550);
	Option2.setTexture(Option2Texture);
	Option2.setScale(sf::Vector2f(0.25, 0.25));
	


	sf::Sprite Option3;    //  search a boogie
	Option3.setPosition(184, 550);
	Option3.setTexture(Option3Texture);
	Option3.setScale(sf::Vector2f(0.25, 0.25));

	sf::Sprite Option4;    // print train info
	Option4.setPosition(373, 550);
	Option4.setTexture(Option4Texture);
	Option4.setScale(sf::Vector2f(0.25, 0.25));

	sf::Sprite Option5;    //reserve a boogie
	Option5.setPosition(562, 550);
	Option5.setTexture(Option5Texture);
	Option5.setScale(sf::Vector2f(0.25, 0.25));

	sf::Sprite Option6;    // Print info of boogie
	Option6.setPosition(751, 550);
	Option6.setTexture(Option6Texture);
	Option6.setScale(sf::Vector2f(0.25, 0.25));

	sf::Sprite Option7;    // Exit
	Option7.setPosition(938, 550);
	Option7.setTexture(Option7Texture);
	Option7.setScale(sf::Vector2f(0.25, 0.25));


	sf::Sprite Option1;    // Add new Boogie
	Option1.setPosition(430, 480);
	Option1.setTexture(Option1Texture);
	Option1.setScale(sf::Vector2f(0.25, 0.25));

	sf::Sprite Logo;   
	Logo.setPosition(340, -20);
	Logo.setTexture(LogoTexture);
	Logo.setScale(sf::Vector2f(0.5, 0.5));
	Logo.setColor(sf::Color::Magenta);


	while (window.isOpen())
	{


		sf::Event evnt;
		while (window.pollEvent(evnt) == true)
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:		//close ur application
				window.close();
				break;

			case sf::Event::Resized:
				sf::FloatRect visiblearea(0, 0, evnt.size.width, evnt.size.height);
				window.setView(sf::View(visiblearea));
			
			}
		}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f sp1pos = Option1.getPosition();
			sf::Vector2f sp2pos = Option2.getPosition();
			sf::Vector2f sp3pos = Option3.getPosition();
			sf::Vector2f sp4pos = Option4.getPosition();
			sf::Vector2f sp5pos = Option5.getPosition();
			sf::Vector2f sp6pos = Option6.getPosition();
			sf::Vector2f sp7pos = Option7.getPosition();
			sf::Vector2f splogo = Logo.getPosition();

			
			if (mousePos.x >352 && mousePos.x<714  && mousePos.y>92  && mousePos.y<148)
			{
				Logo.setTexture(LogoCyberEffect);
			}
			else
			{
				Logo.setTexture(LogoTexture);
			}

			if ((float)mousePos.x > sp1pos.x && (float)mousePos.x<sp1pos.x+179  && (float)mousePos.y>sp1pos.y  && (float)mousePos.y<sp1pos.y+43)    //add a boogie
			{
				Option1.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option1.setColor(sf::Color::White);
					string s1= Input_application("Enter the ID of the boogie you want to Add : \n");
					int ID;
					ID = stoi(s1); // function to convert string to int

					if (t1.SearchBogie(ID) == true)			// if bogie already exist since it's unique
					{
						Print_application("Bogie already exist \n Press any Key to return",20);
					}

					else
					{
						t1.addbogie(ID);
						string res;
						res += "Boogie of ID ";
						res +=  to_string(ID);
						res += "  has been added \n Press any Key to return";
						Print_application(res,20);
					}
				}
			}

			else if ((float)mousePos.x > sp2pos.x && (float)mousePos.x<sp2pos.x + 179 && (float)mousePos.y>sp2pos.y && (float)mousePos.y<sp2pos.y + 43)      //remove a boogie
			{
				Option2.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					int ID_remo;
					string reserve = Input_application("Enter the ID of the Boogie You want to remove\n");
					ID_remo = stoi(reserve);

					if (t1.SearchBogie(ID_remo) == true)
					{
						//delete Person data before deleting boogie

						Bogie* del;
						del = t1.Get_engine();
						Person**ptr1;
						Person **ptr2;

						while (del->get_ID() != ID_remo)
						{
							del = del->Get_nextBogie();
						}
						ptr1 = del->Get_kids();
						ptr2 = del->Get_adult();

						for (int a = 0; a < del->get_checkAdults(); a++)
						{
							delete ptr2[a];
							ptr2[a] = NULL;
						}

						for (int b = 0; b < del->get_checkKids(); b++)
						{
							delete ptr1[b];
							ptr1[b] = NULL;
						}
					}


					t1.removeBogie(ID_remo);
				}
			}

			else if ((float)mousePos.x > sp3pos.x && (float)mousePos.x<sp3pos.x + 179 && (float)mousePos.y>sp3pos.y && (float)mousePos.y<sp3pos.y + 43)     //search a train boogie
			{
				Option3.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option3.setColor(sf::Color::White);
					string ID = Input_application("Enter the ID of the Bogie You want to Search : \n");
					int ID_search = stoi(ID);

					if (t1.SearchBogie(ID_search) == true)
					{
						Print_application("Bogie is found \n Press any key to return",20);
					}
					else
					{
						Print_application("Bogie not found \n Press any key to return",20);
					}

				}
			}

			else if ((float)mousePos.x > sp4pos.x && (float)mousePos.x<sp4pos.x + 179 && (float)mousePos.y>sp4pos.y && (float)mousePos.y<sp4pos.y + 43)     //print train 
			{
				Option4.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option4.setColor(sf::Color::White);
					t1.printTrain(); 
				}
			}

			else if ((float)mousePos.x > sp5pos.x && (float)mousePos.x<sp5pos.x + 179 && (float)mousePos.y>sp5pos.y && (float)mousePos.y<sp5pos.y + 43)    //reserve a boogie
			{
				Option5.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option5.setColor(sf::Color::White);

					check_Adults = 0;
					check_kids = 0;
					string reserve_ID = Input_application("Enter ID of the bogie you want to reserve \n");
					int Id;
					Id = stoi(reserve_ID);

					if (t1.SearchBogie(Id) == false)
					{
						Print_application("No bogie found \n Press any key to return\n",20);
					}
					else if (t1.Boogie_Status(Id) == true)
					{
						Print_application("Sorry Boggie is already reserved..\nPress Any key to return",20);
					}
					else
					{
						string Fam = Input_application("Enter Family name : \n");
						char* Fam_name = new char[1000];
						
						int i = 0;
						for (i; i < Fam.length(); i++)
						{
							Fam_name[i] = Fam[i];
						}
						Fam_name[i] = '\0';

						string pass_count = Input_application("Enter the number of passengers of the bogie : \n");
						int Passenger = stoi(pass_count);
						

						while (Passenger > 10)
						{
							Print_application("Limit exceeded please try again ",20);
							pass_count = Input_application("Enter the number of passengers of the bogie : \n");
							Passenger = stoi(pass_count);
						}
						string temp;
						for (int j = 0; j < Passenger; j++)
						{
							temp += "Passenger ";
							temp += to_string(j + 1);
							temp += " info : ";
							temp += "\n Press A for Adult , K for Kid";
							string opt = Input_application(temp);
							char c;
							c = opt[0];
							temp.clear();
				
							if (c == 'a' || c == 'A')
							{
								if (check_Adults < 4)
								{
									Adults[check_Adults] = new Adult;
									Adults[check_Adults]->addinfo();
									check_Adults++;
								}
								else
								{
									j--;
									Print_application("Limit of boggie exceeded \n cannot add further adults \n Press any Key to return\n",20);
								}
							}
							 if (c == 'k' || c == 'K')
							{
								 if (check_kids < 6)
								 {
									 kids[check_kids] = new kid;
									 kids[check_kids]->addinfo();
									 check_kids++;
								 }
								 else
								 {
									 j--;
									 Print_application("Limit of boggie exceeded \n cannot add further kids  \n Press any Key to return\n",20);
								 }
							}

						}
						t1.Reserve_Bogie(Id, Fam_name, Adults, kids, check_Adults, check_kids);
						delete Fam_name;
						Fam_name = NULL;

					}

				}
			}

			else if ((float)mousePos.x > sp6pos.x && (float)mousePos.x<sp6pos.x + 179 && (float)mousePos.y>sp6pos.y && (float)mousePos.y<sp6pos.y + 43)    //print info of the boogie
			{
				Option6.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option6.setColor(sf::Color::White);

					int id;
					string info=Input_application("Enter the ID of the Bogie to procced : \n");
					id = stoi(info);


					if (t1.SearchBogie(id) == false)
					{
						Print_application("No bogie found \n Press any Key to return",20);
					}
					else
					{
						t1.Print_BogieInfo(id);
					}
					
				}
			}

			else if ((float)mousePos.x > sp7pos.x && (float)mousePos.x<sp7pos.x + 179 && (float)mousePos.y>sp7pos.y && (float)mousePos.y<sp7pos.y + 43)      //Exit the program
			{
				Option7.setColor(sf::Color::Cyan);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Option7.setColor(sf::Color::White);
					window.close();
				}
			}
			else
			{
				Option1.setColor(sf::Color::White);
				Option2.setColor(sf::Color::White);
				Option3.setColor(sf::Color::White);
				Option4.setColor(sf::Color::White);
				Option5.setColor(sf::Color::White);
				Option6.setColor(sf::Color::White);
				Option7.setColor(sf::Color::White);
			}

			window.clear(sf::Color());
			window.draw(background);
			window.draw(Logo);
			window.draw(Option1);
			window.draw(Option2);
			window.draw(Option3);
			window.draw(Option4);
			window.draw(Option5);
			window.draw(Option6);
			window.draw(Option7);

			window.display();

		

	}
	return 0;
}
