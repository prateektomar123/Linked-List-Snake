#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include <Player/Direction.h>

namespace LinkedList
{

	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		int linked_list_size;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node);
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);


	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void insertNodeAtHead();
		void removeNodeAtHead();
		void removeNodeAt(int index);
		void removeNodeAtIndex(int index);
		void shiftNodesAfterRemoval(Node* cur_node);
		int findMiddleNode();
		void insertNodeAtMiddle();
		void removeAllNodes();
		void removeNodeAtMiddle();
		void removeNodeAtTail();
		void updateNodePosition();
		void updateNodeDirection(Direction direction_to_set);

		std::vector<sf::Vector2i> getNodesPositionList();

		bool processNodeCollision();
		Node* getHeadNode();
	};
}