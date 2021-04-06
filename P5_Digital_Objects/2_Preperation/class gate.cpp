    class gate
    {
    public:
        gate() = default;
        gate(bool in_A, bool in_B)
        {
            A = in_A;
            B = in_B;
            Q = 0;
        }

        bool op()
        {
            return Q;
        }

    private:
        bool A;
        bool B;
        bool Q;
    };

    class AND : public gate
    {
    public:
        AND() = default;
        AND(bool in_A, bool in_B)
        {
            A = in_A;
            B = in_B;
            Q = in_A && in_B;
        }

    private:
        bool A;
        bool B;
        bool Q;
    };
    class OR : public gate
    {
    public:
        OR() = default;
        OR(bool in_A, bool in_B)
        {
            A = in_A;
            B = in_B;
            Q = in_A || in_B;
        }

    private:
        bool A;
        bool B;
        bool Q;
    };
    class XOR : public gate
    {
    public:
        XOR() = default;
        XOR(bool in_A, bool in_B)
        {
            A = in_A;
            B = in_B;
            Q = in_A ^ in_B;
        }

    private:
        bool A;
        bool B;
        bool Q;
    };