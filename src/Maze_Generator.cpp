#include "Maze.hpp"
#include <algorithm>
#include <bit>
#include <string>

void Maze::genMazeByMergerMethod()
{
	makeGrid();
	unsigned int size_of_the_merge_array = width * height;
	std::vector<unsigned int> merge_array = std::vector<unsigned int> (size_of_the_merge_array);

	std::default_random_engine generator;
	std::uniform_int_distribution<unsigned int> index_distribution(0, size_of_the_merge_array - 1);
	std::uniform_int_distribution<unsigned char> direction_distribution(0, 3);
	
	/// Fill the Array with 0, 1, 2, etc...
	std::iota(merge_array.begin(), merge_array.end(), 0);


	/// Every Loop we check if the array is fill with only 0
	while (!MergerIsEnded(merge_array))
	{
		unsigned int random_index;
		std::vector<unsigned char> direction_array_choice;

		while (direction_array_choice.size() == 0) 
		{
			random_index = index_distribution(generator);	
			direction_array_choice = getPossibleMergerEdge(merge_array, random_index);	
		}

		std::random_shuffle(direction_array_choice.begin(), direction_array_choice.end());

		unsigned char selected_direction = direction_array_choice[0];
		
		unsigned int actual_index_value = merge_array[random_index];
		unsigned int direction_offset = convertMergerDirectionToOffset(selected_direction);
		unsigned int direction_index_value = merge_array[random_index + direction_offset];

		deleteMergerDirectionWall(random_index, selected_direction);

		if (actual_index_value < direction_index_value)
		{
			std::replace(merge_array.begin(), merge_array.end(), direction_index_value, actual_index_value);
		}
		else 
		{
			std::replace(merge_array.begin(), merge_array.end(), actual_index_value, direction_index_value);
		}
	}
}

bool Maze::MergerIsEnded(std::vector<unsigned int> merge_array)
{
	unsigned int i;
	for (i = 0; i < merge_array.size(); i++)
	{
		if (merge_array[i] != 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<unsigned char>  Maze::getPossibleMergerEdge(std::vector<unsigned int> merge_array, unsigned int index)
{
	/// [Top, Bottom, Left, Right] -> 8 * Top + 4 * Bottom 2 + * Left + 1 * Right
	std::vector<unsigned char> list_of_choices;
	unsigned int index_value = merge_array[index];

	// Check Top:
	if (index >= width)
	{
		if (merge_array[index - width] != index_value)
		{
			list_of_choices.push_back(4);
		}
	}

	// Check Bottom:
	if (index < (height - 1) * width)
	{
		if (merge_array[index + width] != index_value)
		{
			list_of_choices.push_back(3);
		}
	}

	// Check Left:
	if (index % width != 0)
	{
		if (merge_array[index - 1] != index_value)
		{
			list_of_choices.push_back(2);
		}
	}

	// Check Right:
	if (index % width != width - 1)
	{
		if (merge_array[index + 1] != index_value)
		{
			list_of_choices.push_back(1);
		}
	}
	return list_of_choices;
}

unsigned int Maze::convertMergerDirectionToOffset(unsigned char direction)
{
	switch(direction)
	{
		case 1: // R
			return   1;
		case 2: // L
			return - 1;
		case 3: // B 
			return   width;
		case 4: // T
			return - width;
		default: // Impossible
			return 0;
	}
}

void Maze::deleteMergerDirectionWall(unsigned int index, unsigned char direction)
{

	unsigned int x_index = index % width;
	unsigned int y_index = (index - x_index) / width;

	unsigned int content_index = 2 * (width + 1 + x_index + y_index * (2 * width + 1));

	unsigned int offset;

	if (direction == 1)      // R
	{
		offset =   1;
	}
	else if (direction == 2) // L
	{
		offset = - 1;
	}
	else if (direction == 3) // B
	{
		offset =   (2 * width + 1);
	}
	else if (direction == 4) // T
	{
		offset = - (2 * width + 1);
	}
	else  // Impossible
	{
		offset = 0;
	}

	content[content_index + offset] = false;
}


