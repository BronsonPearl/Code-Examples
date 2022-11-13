#include <stdio.h>
#include <cs50.h>



int main(void)
{
    while (true)
    {
        // setting variables for comparison to find what card and store data of card.
        int interval, startNumber, productOdd, productEven;
        bool thirteenFlag;
        long int ccNumber, currentDigit, product, productMulti,  x, y;
        const int visa = 4; //13 or 16 length starts with 4
        const int mastercard = 5; //16 length start with 5. 51, 52, 53, 54, or 55
        const int americanExpress = 3;  //15 digits length start with 3. 34 or 37

        //init units for later
        productEven = 0;
        productOdd = 0;
        product = 0;
        productMulti = 0;
        x = 10;
        y = 1;
        thirteenFlag = false;
        startNumber = 0;


        // prompt for input of credit card number
        ccNumber = get_long("Number: ");


        for (interval = 1; interval < 14; interval++)
        {
            // looking for 13 digit visa
            currentDigit = ccNumber % x;
            x = x * 10;
            startNumber = currentDigit / y;
            y = y * 10;
        }

        if (startNumber == 4)
        {
            thirteenFlag = true;
        }

        if (startNumber != visa)
        {
            // reset start number
            startNumber = 0;
            x = 10;
            y = 1;

            // looking for Amex start number
            for (interval = 1; interval < 16; interval++)
            {
                currentDigit = ccNumber % x;
                x = x * 10;
                startNumber = currentDigit / y;
                y = y * 10;
            }

            if (startNumber != americanExpress)
            {
                startNumber = 0;
                x = 10;
                y = 1;

                // looking for 16 digit VISA or MasterCard
                for (interval = 1; interval < 17; interval++)
                {
                    currentDigit = ccNumber % x;
                    x = x * 10;
                    startNumber = currentDigit / y;
                    y = y * 10;

                }
            }
        }



        if ((startNumber == mastercard) || (startNumber == visa))
        {

            x = 10;
            y = 1;

            //looking for 16 digit card
            //loop for luhns algorithm
            for (interval =  1; interval < 17; interval++)
            {
                //printf("%ld \t %ld \n", x, y);
                currentDigit = ccNumber % x;
                x = x * 10;
                ccNumber = ccNumber - currentDigit;

                if (interval % 2 != 0)
                {
                    //non *2 product added together
                    currentDigit = currentDigit / y;
                    productOdd = currentDigit;
                    product = productOdd + product;
                }

                if (interval % 2 == 0)
                {

                    currentDigit = currentDigit * 2;

                    // adds the multiplied digits together

                    if (currentDigit > 9)
                    {
                        productEven = currentDigit / y;
                        currentDigit = productEven / 10;
                        productEven = (productEven % 10) + currentDigit;
                    }
                    else
                    {
                        productEven = productEven + currentDigit;
                    }

                    productMulti = productEven + productMulti;
                }
                y = y * 10;

            }
        }

        if (thirteenFlag == true)
        {

            x = 10;
            y = 1;
            //loop for luhns algorithm
            for (interval =  1; interval < 14; interval++)
            {
                //printf("%ld \t %ld \n", x, y);
                currentDigit = ccNumber % x;
                x = x * 10;
                ccNumber = ccNumber - currentDigit;

                if (interval % 2 != 0)
                {
                    //non *2 product added together
                    currentDigit = currentDigit / y;
                    productOdd = currentDigit;
                    product = productOdd + product;
                }

                if (interval % 2 == 0)
                {

                    currentDigit = currentDigit * 2;

                    // adds the multiplied digits together

                    if (currentDigit > 9)
                    {
                        productEven = currentDigit / y;
                        currentDigit = productEven / 10;
                        productEven = (productEven % 10) + currentDigit;
                    }
                    else
                    {
                        productEven = productEven + currentDigit;
                    }

                    productMulti = productEven + productMulti;
                }
                y = y * 10;
            }
        }

        else
        {
            x = 10;
            y = 1;

            //loop for luhns algorithm
            for (interval =  1; interval < 16; interval++)
            {
                //printf("%ld \t %ld \n", x, y);
                currentDigit = ccNumber % x;
                x = x * 10;
                ccNumber = ccNumber - currentDigit;

                if (interval % 2 != 0)
                {
                    //non *2 product added together
                    currentDigit = currentDigit / y;
                    productOdd = currentDigit;
                    product = productOdd + product;
                }

                if (interval % 2 == 0)
                {

                    currentDigit = currentDigit * 2;

                    // adds the multiplied digits together

                    if (currentDigit > 9)
                    {
                        productEven = currentDigit / y;
                        currentDigit = productEven / 10;
                        productEven = (productEven % 10) + currentDigit;
                    }
                    else
                    {
                        productEven = productEven + currentDigit;
                    }

                    productMulti = productEven + productMulti;
                }
                y = y * 10;
            }
        }


        //checksum = ends in 0 valid
        product = productMulti + product;


        if (product % 10 != 0)
        {
            printf("INVALID\n");
        }

        else
        {
            //printf what card it is
            switch (startNumber)
            {
                case visa:
                    printf("VISA\n");
                    break;

                case mastercard:
                    printf("MASTERCARD\n");
                    break;

                case americanExpress:
                    printf("AMEX\n");
                    break;

                default:
                    printf("INVALID\n");
            }
        }
    }

    return 0;
}