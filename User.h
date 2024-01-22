class User
{
private:
	int user;
	int pin;
	string name;
public:
	User(int user)		 //Konstruktiorn
	{
		switch (user)
		{
		case 911022:
			name = "Liv Danielsdottir";
			pin = 1111;
			break;
		case 831129:
			name = "Joakim Sjöström";
			pin = 2222;
			break;
		case 841130:
			name = "Meduart Juniku";
			pin = 3333;
			break;
		case 020427:
			name = "Leo Katakalidis";
			pin = 4444;
			break;
		case 920115:
			name = "Jimmy Wallener";
			pin = 5555;
			break;
		default:	  
			name = "No user";
			pin = 0000;
			break;
		}


	}
	int set_user(int users)
	{
		user = users;
	}
	int get_user()
	{
		return user;
	}
	int set_pin(int pins)
	{
		pin = pins;
	}
	int get_pin()
	{
		return pin;
	}
	string set_name(string names)
	{
		name = names;
	}
	string get_name()
	{
		return name;
	}



};