using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary4Try03
{
    public interface ICalculator
    {
        int Add(int a, int b);

    }

    public class Class1:ICalculator
    {

        public int Add(int a,int b)
        {
            return (a + b);
        }

    }
}
