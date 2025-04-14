#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int ListSize = 0;


void arr_insertAtEnd(int value) {
    if (ListSize < MAX_SIZE) {
        arr[ListSize] = value;
        ListSize++;
    } else {
        cout << "Lista llena" << endl;
    }
}

void arr_deleteFromEnd() {
    if (ListSize > 0) {
        ListSize--;
    } else {
        cout << "Lista vacía" << endl;
    }
}

bool arr_search(int value) {
    for (int i = 0; i < ListSize; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void arr_display() {
    for (int i = 0; i < ListSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//!Enlazada

struct Node {
    int data;
    int next;
};

const int MAX_NODES = 100;
Node list[MAX_NODES];
int head = -1;
int freeHead = 0;

void initializeFreeList() {
    for (int i = 0; i < MAX_NODES - 1; i++) {
        list[i].next = i + 1;
    }
    list[MAX_NODES - 1].next = -1;
}

int getFreeNode() {
    if (freeHead == -1) {
        cout << "No hay más nodos libres" << endl;
        return -1;
    }
    int nodeIndex = freeHead;
    freeHead = list[freeHead].next;
    return nodeIndex;
}

void freeNode(int index) {
    list[index].next = freeHead;
    freeHead = index;
}

void ll_insertAtBeginning(int value) {
    int newNode = getFreeNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = head;
    head = newNode;
}

void ll_insertAtEnd(int value) {
    int newNode = getFreeNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = -1;
    if (head == -1) {
        head = newNode;
    } else {
        int current = head;
        while (list[current].next != -1) {
            current = list[current].next;
        }
        list[current].next = newNode;
    }
}

void ll_deleteFromBeginning() {
    if (head == -1) {
        cout << "Lista vacía" << endl;
        return;
    }
    int temp = head;
    head = list[head].next;
    freeNode(temp);
}

bool ll_search(int value) {
    int current = head;
    while (current != -1) {
        if (list[current].data == value) {
            return true;
        }
        current = list[current].next;
    }
    return false;
}

void ll_display() {
    int current = head;
    while (current != -1) {
        cout << list[current].data << " ";
        current = list[current].next;
    }
    cout << endl;
}

int main() {
    cout << "Ejemplo de lista basada en arreglos:" << endl;
    arr_insertAtEnd(1);
    arr_insertAtEnd(2);
    arr_insertAtEnd(3);
    cout << "Lista después de insertar 1, 2, 3: ";
    arr_display();
    arr_deleteFromEnd();
    cout << "Lista después de eliminar el último elemento: ";
    arr_display();
    cout << "Buscar 2: " << (arr_search(2) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 3: " << (arr_search(3) ? "Encontrado" : "No encontrado") << endl;

    ListSize = 0;

    cout << "\nEjemplo de lista enlazada basada en arreglos:" << endl;
    initializeFreeList();
    ll_insertAtBeginning(1);
    ll_insertAtBeginning(2);
    ll_insertAtBeginning(3);
    cout << "Lista después de insertar 1, 2, 3 al inicio: ";
    ll_display();
    ll_deleteFromBeginning();
    cout << "Lista después de eliminar el primer elemento: ";
    ll_display();
    cout << "Buscar 2: " << (ll_search(2) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 3: " << (ll_search(3) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}