#include "LinkedList/SingleLinkedList.h"
#include "Player/BodyPart.h"
#include "Level/LevelView.h"
#include <iostream>

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList() = default;
	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}
	void SingleLinkedList::render()
	{
		head_node->body_part.render();
	}
	void SingleLinkedList::createHeadNode()
	{
		head_node = createNode();
		head_node->body_part.initialize(node_width, node_height, default_position, default_direction);
		return;
	}
	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}
}