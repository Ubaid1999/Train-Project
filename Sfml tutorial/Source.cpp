#include"SFML\Graphics.hpp"
#include<iostream>
#include<string>

using namespace std;



int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "trial", sf::Style::None);
	sf::String input;

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text playerinput;
	playerinput.setFont(font);
	playerinput.setStyle(sf::Text::Regular | sf::Text::Underlined);
	playerinput.setCharacterSize(38);
	playerinput.setFillColor(sf::Color::White);


	while (window.isOpen())
	{
		sf::Event evnt3;
		while (window.pollEvent(evnt3)==true)
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
					input += '\n';
					window.close();
				}
				if (evnt3.text.unicode == '\b')
				{
						input.erase(input.getSize() - 2, 2);
						playerinput.setString(input);
				
				}
			}
		}

		window.clear();
		window.draw(playerinput);
		window.display();



	}
	
	string s = input;

	char* test = new char[10];

	int i = 0;
	for (i ; i < s.length(); i++)
	{
		test[i] = s[i];
	}
	test[i] = '\0';
	

	cout << test;
	
	//how to store string in dynamic array character

	/*int Id;

	Id = stoi(s);

	cout << Id;*/

	

	system("pause");
}