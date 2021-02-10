#include <utility>
#include <set>
#include <iostream>
#include <queue>
#include <queue>
#include <deque>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <random>
#include <sstream>
#include <thread>
#include <initializer_list>

using namespace std ;



namespace Blink {
namespace  concurrencia{


template<typename valor>
struct NodeBLink;

template<typename valor>
struct Node {
	valor value;
	NodeBLink<valor>* left;
	NodeBLink<valor>* right;
	Node(valor val, NodeBLink<valor>* left_ = NULL, NodeBLink<valor>* right_ = NULL) {
		value = val;
		left = left_;
		right = right_;
	}
	int getVal() const { return value; }
	NodeBLink<valor>* getL() const { return l; }
	NodeBLink<valor>* getR() const { return r; }
	void setLeft(NodeBLink<valor> x)const {
		left = &x;
	}
	void setRight(NodeBLink<valor> x)const {
		right = &x;
	}

};
/*

				Vcab
			
		Vn     				 Vn
	
 Vhoj    	Vhoj  		 Vhoj  		  Vhoj



*/
template<typename valor>
struct NodeBLink {
	std::set<Node<valor>, classp<valor> > valores;
	NodeBLink<valor>* parent;
	std::set<Node<valor>, classp<valor> >* left;
	std::set<Node<valor>, classp<valor> >* right;
	NodeBLink() { left = right = NULL;  parent = NULL; }
};
template<typename valor>
struct classp {
	bool operator() (Node<valor> a, Node<valor> b)const
	{
		return a.value < b.value;
	}
};

bool VacioT() const {		
		if (!root) { return 1; }
		return 0;
	}
	
template <std::size_t tam, typename Type>
class ArbolBlink {
 public:
	typedef Type data_type;
	ArbolBlink() { root = NULL; }
	~ArbolBlink() {}
	std::size_t size() const {
		size_t tam = 0;
		if (!root) { return 0; }
		else {
			NodeBLink<data_type>* viajero = root;
			std::queue<NodeBLink<data_type>*> cola;
			cola.push(viajero);
			bool colaP = 1;
			while (!cola.empty()) {
				NodeBLink<data_type>* temp = cola.front();
				NodeBLink<data_type>* iter = temp->valores.begin();
				if(iter->l == NULL){
					viajero = temp;
					while(bust->right){
						tam += bust->valores.size();
						viajero = bust->right;
					}
					tam += bust->valores.size();
					cola.pop();
				}
				else{
					cola.push(iter->l);
					cola.pop();
				}
			}
		}
		return tam;
	}
		bool insertar(const data_type& value) {
		int medio = tam/2;
		if (!root) {
			root = new NodeBLink<data_type>();
			Node<data_type> nuevo(value);
			root->valores.insertar(nuevo);
		}
		else {
			NodeBLink<data_type>* viajero = root;
			std::queue<NodeBLink<data_type>*> cola;
			cola.push(viajero);
			bool colaP = 1;
			while (!cola.empty() && colaP) {
				NodeBLink<data_type>* temp = cola.front();
				NodeBLink<data_type>*iter = temp->valores.begin();
				for (; iter != temp->valores.end(); iter++) {
					if (iter->value > value) {
						if (iter->l == NULL) {
							bust = temp;
							colaP = 0;
							cola.pop();
							break;
						}
						else {
							cola.push(iter->l);
							cola.pop();
							break;
						}
					}
				}
				if (iter == temp->valores.end()) {
					iter--;
					if (iter->r == NULL) {
						viajero = temp;
						colaP = 0;
					}
					else {
						cola.push(iter->r);
						cola.pop();
					}
				}
		
			}
			Node<data_type> nuevo(value);
			bust->valores.insertar(nuevo);
			int cont = 0;
			while (bust->valores.size() >= tam) {
				NodeBLink<data_type>* prev = new NodeBLink<data_type>();
				int contador_medio = 0;
				while (contador_medio < medio) {
				NodeBLink<data_type>*it = bust->valores.begin();
					Node<data_type> copia(it->getVal(), it->getL(), it->getR());
					prev->valores.insertar(copia);
					if (cont > 0) {
						it->getL()->parent = it->getR()->parent = prev;
					}
					bust->valores.erase(it->value);
					contador_medio++;
				}
				int valorM = 0;
				NodeBLink<data_type>* valu = bust->valores.begin();
				valorM = valu->value;
				if (bust->parent == NULL) {
					NodeBLink<data_type>* nueva_raiz = new NodeBLink<data_type>();
					Node<data_type> nodo_nueva_raiz(valorM, prev, bust);
					nueva_raiz->valores.insertar(nodo_nueva_raiz);
					prev->parent = bust->parent = nueva_raiz;
					this->root = nueva_raiz;
					prev->right = bust;
					if(bust->left == NULL){
						bust->left = prev;
					}
					else{
						prev->left = bust->left;
						bust->left->right = prev;
						bust->left = prev;
					}
					
				if (cont > 0) {
					NodeBLink<data_type>*it = bust->valores.begin();
					bust->valores.erase(it->value);
				}
				

				}
				else {
					NodeBLink<data_type>* parentTemp = bust->parent;
					Node<data_type> nodo_nueva_padre(valorM, prev, bust);
					parentTemp->valores.insertar(nodo_nueva_padre);
                    NodeBLink<data_type>* piv = bust;
                    NodeBLink<data_type>* prev_aux = prev;
                    prev_aux->parent = piv->parent = parentTemp;
					NodeBLink<data_type>* iterR = parentTemp->valores.begin();
					if (iterR->value == valorM) {
						NodeBLink<data_type>* tempIR = iterR;
						tempIR++;
						Node<data_type> nodo_nuevo(tempIR->getVal(), piv, tempIR->getR());
						parentTemp->valores.erase(tempIR->getVal());
						parentTemp->valores.insertar(nodo_nuevo);
                        tempIR->getR()->parent = piv->parent = parentTemp;
					}
					else {
						for (; iterR != parentTemp->valores.end(); iterR++) {
						NodeBLink<data_type>* tempIR = iterR;
							tempIR++;
							if (tempIR->value == valorM) {
								Node<data_type> nodo_nuevo(iterR->getVal(), iterR->getL(), prev_aux);
								parentTemp->valores.erase(iterR->getVal());
								parentTemp->valores.insertar(nodo_nuevo);
                                iterR->getL()->parent = prev_aux->parent = parentTemp;
								break;
							}
						}
						iterR = parentTemp->valores.begin();
						for (; iterR->value != valorM; iterR++) {}
						iterR++;
                        piv = bust;
						if (iterR != parentTemp->valores.end()) {
							Node<data_type> nodo_nuevo(iterR->getVal(), piv, iterR->getR());
							parentTemp->valores.erase(iterR->getVal());
							parentTemp->valores.insertar(nodo_nuevo);
                            iterR->getR()->parent = piv->parent = parentTemp;
						}
					}
					prev->right = bust;
					if(bust->left == NULL){
						bust->left = prev;
					}
					else{
						prev->left = bust->left;
						bust->left->right = prev;
						bust->left = prev;
					}
					bust = bust->parent;
				}
				cont++;
			}
		}std::cout << "Valor insertado correctamente" << value << "\n";
		return 1;
	}
	/*	void remove(const data_type& value) {
		
	  Node** ptr = NULL; 
	  Node** ptr_dad = NULL;
	  bool internal = false;
	  std::queue<Node*> locks;
	  if (!(search(value, ptr, ptr_dad, locks))) {
		  return;
	  }
	  if ((*ptr)->size == tam/2 ) {// si es necesario hacer split
		  //std::cout << "Time to unsplit" << std::endl;
	  }
	  else {
		  for (int i = 0; i < (*ptr)->size; ++i) {//recorre la hoja
			  if ((*ptr)->values[i] == value) {
				  (*ptr)->values[i] = 0;
			  }
		  }
		  (*ptr)->size--;
		  BSort((*ptr)->values, ((*ptr)->size) - 1);
	  }
  }
*/

	bool buscar1(const data_type& value) const {

		if (!root) { return 0; }
		else {

			NodeBLink<data_type>* bust = root;

			std::queue<NodeBLink<data_type>*> cola;
			cola.push(bust);
			bool colaP = 1;

			while (!cola.VacioT() && colaP) {
				NodeBLink<data_type>* temp = cola.front();
				NodeBLink<data_type>* iter = temp->valores.begin();
				if (iter == temp->valores.end()) {
					iter--;
					if (iter->r == NULL) {
						bust = temp;
						colaP = 0;
					}
					else {
						cola.push(iter->r);
						cola.pop();
					}
				}

				for (; iter != temp->valores.end(); iter++) {
					if (iter->value > value) {
						if (iter->l == NULL) {
							bust = temp;
							colaP = 0;
							cola.pop();
							break;
						}
						else {
							cola.push(iter->l);
							cola.pop();
							break;
						}
					}
				}

			}
			
			bool res = bust->valores.count(value);
			if (res) { std::cout << "VALOR : " << value << "\n"; return 1; }
			else { std::cout << "VALOR " << value << "\n"; return 0; }

		}
	}


 private:
	NodeBLink<data_type>* root;

};

} 
}  
