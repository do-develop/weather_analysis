#ifndef VECTOR_H
#define VECTOR_H
//-------------------------------------------------------------
//-------------------------------------------------------------
/**
 * @class Vector
 * @brief Customized minimum vector class
 *
 * @author Doyoung Oh
 * @version 01
 * @date 21/09/2020 Created Vector class for minimal operations for lab5
 *
 * @author Doyoung Oh
 * @version 02
 * @date 25/09/2020 Rule of Three applied
 *
 * @author Doyoung Oh
 * @version 03
 * @date 16/11/2020 During the exam preparation, this class is revised and improved.
 */
//-------------------------------------------------------------------
//CLASS DEFINITION
//-------------------------------------------------------------------
template<typename T>
class Vector
{
public:
    /**
     * @brief default constructor for Vector
     */
    Vector();

    /**
     * @brief constructor that takes in the size to initialize
     * @param size of the vector to initialize
     */
    explicit Vector(unsigned int size);
//RULE OF THREE------------------------------------------------------
//-------------------------------------------------------------------

    /**
     * @brief default destructor to prevent memory leak
     */
    ~Vector();

    /**
     * @brief copy constructor of this Vector class
     */
    Vector(const Vector<T> & cp);


    /**
     * @brief copy assignment operator of this Vector class
     */
    Vector & operator=(const Vector<T> & cp);


//-------------------------------------------------------------------
//-------------------------------------------------------------------
    /**
     * @brief get the capacity of the Vector
     * @return capacity value in unsigned type
     */
    unsigned GetCapacity() const;

    /**
     * @brief get the last index position of the Vector
     * @return last value in unsigned type
     */
    unsigned GetLast() const;

    /**
     * @brief get the array of the Vector
     * @return template type pointer to the arr
     */
    T* GetArray() const;

    /**
     * @brief add data at the end of the array
     *
     * @param template type data
     * @return void
     */
    void Insert(const T data);

    /**
    *@brief deletes last element of Vector
    */
    void Remove();

    /**
     * @brief retrieves the element at the index position
     *
     * @param index is the integer value indicating the position of the array
     * @return template type reference
     */
    T& At(int index) const;

    /**
     * @brief method to check if the Vector is empty
     * @return it returns true if the Vector is empty, false, if not.
     */
    bool IsEmpty();

private:
    T* arr; ///template type array pointer
    unsigned int last;  ///last element index
    unsigned int capacity;  ///capacity of the array

    /**
     * @brief This resizes the capacity of the Vector
     * @return void
     */
    void Resize();

    /**
     * @brief this enables the deep copy of the object
     * @param the other Vector object to be copied
     */
    void Copy(const Vector<T>& cp);

};
//CONSTRUCTORS--------------------------------------------------
//--------------------------------------------------------------
template<typename T>
Vector<T>::Vector() //default constructor
{
    arr = nullptr;
    last = 0;
    capacity = 10; //default capacity

    arr = new T[capacity];
}

template<typename T>
Vector<T>::Vector(unsigned int size)
{
    arr = nullptr;
    last = 0;
    capacity = size;

    arr = new T[capacity];
}
//RULE OF THREE-------------------------------------------------
//--------------------------------------------------------------
template<typename T>
Vector<T>::~Vector() //destructor
{
    delete[] arr;
}

template<typename T>
Vector<T>::Vector(const Vector<T> & cp) //copy constructor
{
    Copy(cp);
}

template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T>& cp) //copy assignment operator
{
    Copy(cp);
    return *this;
}

//PRIVATE METHODS----------------------------------------------
//-------------------------------------------------------------
template<typename T>
void Vector<T>::Copy(const Vector<T>& cp) //actual deep copy is handled by this method
{
    last = cp.GetLast();
    capacity = cp.GetCapacity();

    arr = new T[capacity];
    for (unsigned i=0; i<last; i++)
    {
        arr[i] = cp.At(i);
    }
}

template<typename T>
void Vector<T>::Resize()
{
    int newCapacity = capacity * 1.5;
    T* newArr = new T[newCapacity];
    if (newArr != nullptr) //if 'new' does not fail
    {
        for(unsigned i=0; i<capacity; i++) //bound checking 'i<capacity'
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
}

//MINIMUM METHODS TO ASSIGN AND RETRIEVE DATA-------------------
//--------------------------------------------------------------

template<typename T>
void Vector<T>::Insert(const T data)
{   //If the last is equal to or bigger than the capacity, the size needs to be increased
    if (last>=capacity)
    {
        Resize();
    }
    arr[last] = data;
    last++;
}

template<typename T>
T& Vector<T>::At(int index) const
{
    return arr[index];
}

template<typename T>
void Vector<T>::Remove()
{
    if(last<0)
    {
        return;
    }
    last--;
}
//GET METHODS---------------------------------------------------
//--------------------------------------------------------------
template<typename T>
unsigned Vector<T>::GetCapacity() const
{
    return capacity;
}

template<typename T>
unsigned Vector<T>::GetLast() const
{
    return last;
}

template<typename T>
T* Vector<T>::GetArray() const
{
    return arr;
}

//Minimum but complete-----------------------------------------
//-------------------------------------------------------------
template<typename T>
bool Vector<T>::IsEmpty()
{
    return (last==0);
}
//-------------------------------------------------------------
//-------------------------------------------------------------
#endif // VECTOR_H
