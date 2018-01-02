#include "queue.h"

static node_t* delete_node(node_t *node, void (*free_node)(void *))
{

	node_t* tmp;
	if(node != NULL){
		tmp = node;
		node = node->next;
		free_node(tmp);
		free(tmp);
	}

	return node;
}

static node_t* free_node_t(node_t *node, void (*free_node)(void *))
{

	while(node!=NULL){
		node = delete_node(node, free_node);
	}
	return node;

}

void enqueue(queue_t *queue, void *data) 
{
	node_t *tmp = malloc(sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
	if(queue->head==NULL){
		queue->head=tmp;
		queue->tail=tmp;
	}else{
		queue->tail->next=tmp;
		queue->tail=tmp;

	}
	queue->length += 1;
}

void dequeue(queue_t* queue)
{
	queue->head = delete_node(queue->head, queue->free_node);
	if(queue->head==NULL){
		queue->head=NULL;
	}
	if (queue->length > 0)
		queue->length -= 1;
}

void free_queue(queue_t* queue)
{
	queue->head = free_node_t(queue->head, queue->free_node);
	queue->tail=NULL;

	queue->length = 0;
}

queue_t* init_queue(void (*free_node)(void *))
{
	queue_t *queue = malloc(sizeof(queue_t));
	queue->head = NULL;
	queue->tail = NULL;
	queue->length = 0;
	queue->free_node = free_node;

	return queue;
}