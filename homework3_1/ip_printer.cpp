#include <type_traits>
#include <iostream>
#include <cstddef>
#include <array>
#include <list>
#include <tuple>
#include <typeinfo>
//
template<class T>
struct is_numeric : std::false_type {};
 
template<>
struct is_numeric<int> : std::true_type {};

template<>
struct is_numeric<long> : std::true_type {};

template<>
struct is_numeric<short> : std::true_type {};
//

//
template<class T>
struct is_not_string : std::true_type {};
 
template<>
struct is_not_string<std::string> : std::false_type {};
//

template <typename T, typename N>
constexpr bool is_same_type(T current_type, N next_tupe)
{
    return std::is_same<T, N>::value;
}
template <size_t I = 0, typename... Ts>
void printTuple(std::tuple<Ts...> tup)
{
    if
        (I == sizeof...(Ts))
        {
            std::cout<<std::endl;
            return;
        }
    else {
        
        std::cout << std::get<I>(tup);
        if(I+1 != sizeof...(Ts)) std::cout<< ".";
        if(!is_same_type(I, I+1)) throw std::bad_typeid();
        printTuple<I + 1>(tup);
    }
}
//

//
struct failure;

template <class Container>
struct has_begin {
    template<typename T, typename N>
    static decltype(std::declval<T, N>().begin()) detect(T);
    static failure detect(...);
    static constexpr bool value = !std::is_same<failure, decltype(detect(std::declval<Container>()))>;
};
//

template <typename T>       struct is_vector:std::false_type{};
template <typename... Args> struct is_vector<std::vector <Args...>>:std::true_type{};

template <typename T>       struct is_list:std::false_type{};
template <typename... Args> struct is_list<std::list <Args...>>:std::true_type{};

template< class T >
struct is_container : has_begin<T>, is_not_string<T> {};

template <typename T>       struct is_tuple:std::false_type{};
template <typename... Args> struct is_tuple<std::tuple <Args...>>:std::true_type{};

//char
template<typename T>
std::enable_if_t<std::is_same<T, char>::value> print_ip(T ip_input)
{
    std::byte byte_input = (std::byte) ip_input;
    std::cout<<std::to_integer<int>(byte_input)<<std::endl;
}
    
//long, short, int
template<typename T>
std::enable_if_t<is_numeric<T>::value> print_ip(T ip_input) {

    int input_size = sizeof(T);
    int bytes = 8;
    const char ip_delimeter = '.';
    int byte_shift = input_size * bytes;
    
    for (int i = 0; i < input_size; i++)
    {
        byte_shift -= bytes;
        const T value_with_shift = ip_input>>byte_shift;
        std::byte current_byte = static_cast<std::byte>(value_with_shift);
        current_byte = current_byte & std::byte{0xFF};
        std::cout<<std::to_integer<T>(current_byte);
        if (i != input_size - 1) std::cout<<ip_delimeter;
    }
    
    std::cout<<std::endl;

}

//std::string
template<typename T>
std::enable_if_t<!is_not_string<T>::value> print_ip(T ip_input) {

    std::cout<<ip_input<<std::endl;
    
}

//std::list, std::vector
template<typename T>
std::enable_if_t<is_list<T>::value || is_vector<T>::value> print_ip(T ip_input) {

    for (auto it = ip_input.begin(); it != ip_input.end();  ++it )
    {
        std::string delimeter = it == --ip_input.end() ? "": ".";
        std::cout<<*it<<delimeter;
    }
    
    std::cout<<std::endl;
}

template<typename T>
std::enable_if_t<is_tuple<T>::value> print_ip(T ip_input) {
    
    printTuple(ip_input);
    
}
