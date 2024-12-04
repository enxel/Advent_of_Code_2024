#include <bits/stdc++.h>
//#include <fstream>

using namespace std;

class MinHeap {
    private:
        int heapsize;
        int* heap;

        //Función para obtener, dado el índice de un nodo, el índice de su padre
        int parent(int i){
            return (i-1)/2; //El floor se ejecuta automáticamente por devolverse como int
        }

        //Función para obtener, dado el índice de un nodo, el índice de su hijo izquierdo
        int left(int i){
            return 2*i + 1;
        }

        //Función para obtener, dado el índice de un nodo, el índice de su hijo derecho
        int right(int i){
            return 2*i + 2;
        }

        //Función que, si la relación entre un nodo y sus hijos no cumple las especificaciones
        //de un montículo de máximos, corrige la situación poniendo como padre al dato más
        //grande de los tres
        void min_heapify(int i){
            //cout << "\tMin-heapifying from: " << i << "\n";
            //Se preparan variables auxiliares
            int smallest, temp;

            //Se obtienen los índices de los hijos en el arreglo
            int l = left(i);
            int r = right(i);
            //cout << "\tChildren at: " << l << " and " << r <<"\n";

            //Si el hijo izquierdo existe, se determina quién es más grande entre él y el padre
            if( l <= heapsize && heap[l] < heap[i] )
                smallest = l;
            else
                smallest = i;

            //Si el hijo derecho existe, se determina quién es más grande entre él y el ganador anterior
            if( r <= heapsize && heap[r] < heap[smallest] )
                smallest = r;

            //cout << "\tSmallest at: " << smallest << "\n";

            //Si el padre no quedó como el más grande, se intercambia con el más grande de sus hijos
            if( smallest != i ){
                //cout << "\t\tSwapping " << i << " with " << smallest << "\n";
                swap(heap[i], heap[smallest]);
                //En la nueva posición del padre puede haberse roto también la propiedad de montículo,
                //por lo que se envía a recursión para corregirlo
                min_heapify(smallest);
            }
        }

        //Función que transforma el contenido de un arreglo en un montículo
        //En este caso se trabaja con un montículo de máximos
        void build_min_heap(){
            //Se corrige el contenido del arreglo para que cumpla las propiedades de un montículo de máximos
            //Se trabaja desde la mitad del arreglo en reversa, ya que la segunda mitad son las hojas del montículo
            //(lo anterior es una propiedad demostrable, si el lector está interesado puede consultarlo con el docente)
            int temp_heapsize = heapsize;
            for(int i = temp_heapsize/2; i >= 0; i--) //El floor se ejecuta automáticamente por almacenarse en un int
                min_heapify(i);
        }


    public:
        MinHeap (int n){
            heapsize = -1;
            heap = (int*) malloc(sizeof(int)*n);
        }

        int getHeapsize(){
            return heapsize;
        }

        void add(int v){
            //cout << "Adding: " << v << "\n";
            heapsize++;
            //cout << "New heapsize: " << heapsize << "\n";
            heap[heapsize] = v;
            build_min_heap();
        }

        void show(){
            cout << "[ ";
            for(int i = 0; i <= heapsize; i++)
                cout << heap[i] << " ";
            cout << "]\n";
        }

        int extract_min(){
            int min = heap[0];
            swap(heap[0],heap[heapsize]);
            heapsize--;
            build_min_heap();
            return min;
        }
};

int main(void){
    int a, b;
    vector<int> L1, L2;

    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");
    while(inputFile >> a){
        inputFile >> b;
        L1.push_back(a);
        L2.push_back(b);
    }
    inputFile.close();

    MinHeap h1(L1.size()), h2(L2.size());

    for(int i = 0; i < L1.size(); i++){
        h1.add(L1.at(i));
        h2.add(L2.at(i));
    }

    //h1.show();
    //cout << "----------------------\n";
    //h2.show();

    int limit = h1.getHeapsize();
    int acum = 0;
    for(int i = 0; i <= limit; i++)
        acum += abs(h1.extract_min()-h2.extract_min());
    
    cout << acum << "\n";

    return 0;
}