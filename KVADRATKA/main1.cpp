const char *GetCountOfRoots(count_of_roots n_roots)
{
    switch (n_roots)
    {
        case NO_ROOTS:
            return "NO_ROOTS";
            break;
        case ONE_ROOT:
            return "ONE_ROOT";
            break;
        case TWO_ROOTS:
            return "TWO_ROOTS";
            break;
        case INFIN_ROOTS:
            return "INFIN_ROOTS";
            break;
        default:
            printf("Error of running test! Count of roots is incorrect \n");
            break;
    }

    return "\0";
}

bool IsDifferentF(float num_1, float num_2)
{
    if (isnan(num_1) || isnan(num_2)) {
        if (isnan(num_1) && isnan(num_2))
            return false;
        else
            return true;
    }

    return (fabs(num_1 - num_2) > LOWCONST);
}

bool IsZeroF(float num)
{
    return !IsDifferentF(num, 0);
}