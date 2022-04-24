class Helpers{
public:
    template<typename TK, typename TV>
    static std::vector<TV> extract_values_from_map(std::map<TK, TV> const& input_map){
      std::vector<TV> retval;
      for (auto const& element : input_map) {
        retval.push_back(element.second);
      }
      return retval;
    }
};