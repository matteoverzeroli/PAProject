class User {/*...*/}

class Administrator : virtual public User {/*...*/}

class Volunteer : virtual public User {/*...*/}

class Foreman: public Administrator, public Volunteer {/*...*/}