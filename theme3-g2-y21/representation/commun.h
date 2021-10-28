struct etudiant_s {
    unsigned int numero;
    float moyenne;
};

union bloc_u {
    struct etudiant_s etu;
    char data[sizeof(struct etudiant_s)];
};
