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

//! Enlazada

struct Node {
    int data;
    Node* next;  // Cambiado de int a puntero Node*
};

Node* head = nullptr;  // Puntero al primer nodo, inicializado como nullptr

void ll_insertAtBeginning(int value) {
    
    Node* newNode = new Node();  // Crear un nuevo nodo dinámicamente
    newNode->data = value;
    newNode->next = head;  // El nuevo nodo apunta al antiguo head
    head = newNode;  // El nuevo nodo se convierte en el head
}

void ll_insertAtEnd(int value) {

    Node* newNode = new Node();  // Crear un nuevo nodo dinámicamente
    newNode->data = value;
    newNode->next = nullptr;  // El nuevo nodo será el último
    if (head == nullptr) {  // Si la lista está vacía
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {  // Buscar el último nodo
            current = current->next;
        }
        current->next = newNode;  // Conectar el nuevo nodo al final
    }
}

void ll_deleteFromBeginning() {
    if (head == nullptr) {  // Verificar si la lista está vacía
        cout << "Lista vacía" << endl;
        return;
    }
    Node* temp = head;  // Guardar el nodo a eliminar
    head = head->next;  // Mover head al siguiente nodo
    delete temp;  // Liberar la memoria del nodo eliminado
}

bool ll_search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void ll_display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {



    ll_insertAtBeginning(4);
    ll_insertAtBeginning(2);
    cout << head << endl;
    cout << head->data << endl;
    cout << head->next << endl;

    /*
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

    cout << "\nEjemplo de lista enlazada:" << endl;
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
    */

    return 0;
}