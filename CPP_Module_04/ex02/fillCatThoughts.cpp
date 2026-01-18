#include <cstdlib>
#include <ctime>
#include <string>
#include "Brain.hpp"

void	fillCatThoughts(Brain* brain)
{
	const std::string subjects[] = {
		"I", "ME", "CAT", "CUTE CAT", "STARVING CAT", "FAT CAT"
	};

	const std::string verbs[] = {
		"WANT", "NEED", "HUNT", "PLAY", "HEAR", "COMMAND", "SCRATCGH"
	};

	const std::string objects[] = {
		"FOOD",
		"BALL",
		"HUMAN",
		"MOUSE",
		"DOG",
		"SOFA",
		"OUTSIDE",
		"TREATS",
		"SHOES"
	};

	const std::string emotions[] = {
		"NOW",
		"SOON",
		"FOREVER",
		"RIGHT NOW",
		"VERY MUCH",
		"CAT COMMAND"
	};

	const int subjCount = sizeof(subjects) / sizeof(subjects[0]);
	const int verbCount = sizeof(verbs) / sizeof(verbs[0]);
	const int objCount  = sizeof(objects) / sizeof(objects[0]);
	const int emoCount  = sizeof(emotions) / sizeof(emotions[0]);

	std::string catThoughts[100];

	std::srand(std::time(NULL));

	for (int i = 0; i < 100; ++i)
	{
		catThoughts[i] =
			subjects[std::rand() % subjCount] + " " +
			verbs[std::rand() % verbCount] + " " +
			objects[std::rand() % objCount] + " " +
			emotions[std::rand() % emoCount];
	}
	brain->setIdeas(catThoughts);
}
