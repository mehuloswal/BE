package Calculator;

import static org.junit.Assert.*;

import org.junit.Test;

public class CalculatorTest {

	@Test
	public void testAdd() {
		Calculator calc=new Calculator();
		int result=calc.add(100,200);
		assertEquals(300,result);
	}

	@Test
	public void testSubstract() {
		Calculator calc=new Calculator();
		int result=calc.substract(200,100);
		assertEquals(100,result);
	}

	@Test
	public void testMultiply() {
		Calculator calc=new Calculator();
		int result=calc.multiply(2,100);
		assertEquals(100,result);
	}

}
