class Fixed {
public:
    Fixed(void);
    Fixed(Fixed const &old);
    ~Fixed(void);
    Fixed &operator=(Fixed const &rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int m_Value;
    static const int m_FractionBits;
};
