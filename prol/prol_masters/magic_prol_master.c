unsigned char cmd_byte = *(unsigned char*)get_prol_stack(&file_byte_stack, _i);

if (cmd_byte == 1)
{

	DEF_MAGIC_PROL_MASTER("lin", cmd_byte, 1, NULL, {}, 
	{

		long long temp = 0;
		scanf("%lld", &temp);
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 2)
{

	DEF_MAGIC_PROL_MASTER("din", cmd_byte, 1, NULL, {}, 
	{

		double temp = 0;
		scanf("%lf", &temp);
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 3)
{

	DEF_MAGIC_PROL_MASTER("lout", cmd_byte, 1, NULL, {}, 
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		printf("%lld\n", temp);
		fflush(stdout);
	}, false, 0)	
}
else if (cmd_byte == 4)
{

	DEF_MAGIC_PROL_MASTER("dout", cmd_byte, 1, NULL, {}, 
	{

		double temp = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		printf("%lf\n", temp);
		fflush(stdout);
	}, false, 0)	
}
else if (cmd_byte == 5)
{

	DEF_MAGIC_PROL_MASTER("pop", cmd_byte, 1, NULL, {}, 
	{

		pop_prol_stack(&cpu_byte_stack);
	}, false, 0)	
}
else if (cmd_byte == 6)
{

	DEF_MAGIC_PROL_MASTER("sqrt", cmd_byte, 1, NULL, {}, 
	{

		double temp = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		temp = sqrt(temp);
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 7)
{

	DEF_MAGIC_PROL_MASTER("lsqr", cmd_byte, 1, NULL, {}, 
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		temp = temp * temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)	
}
else if (cmd_byte == 8)
{

	DEF_MAGIC_PROL_MASTER("dsqr", cmd_byte, 1, NULL, {}, 
	{

		double temp = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		temp = temp * temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 9)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 1, NULL, {}, 
	{

		long long temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp += temp2;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 10)
{

	DEF_MAGIC_PROL_MASTER("dadd", cmd_byte, 1, NULL, {}, 
	{

		double temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp += temp2;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 11)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 1, NULL, {}, 
	{

		long long temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp *= temp2;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)	
}
else if (cmd_byte == 12)
{

	DEF_MAGIC_PROL_MASTER("dmul", cmd_byte, 1, NULL, {}, 
	{

		double temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp *= temp2;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)	
}
else if (cmd_byte == 13)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 1, NULL, {}, 
	{

		long long temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp = temp2 / temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 14)
{

	DEF_MAGIC_PROL_MASTER("ddiv", cmd_byte, 1, NULL, {}, 
	{

		double temp  = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp = temp2 / temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 15)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 1, NULL, {}, 
	{

		long long temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp = temp2 % temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 16)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 1, NULL, {}, 
	{

		long long temp  = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp = temp2 - temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 17)
{

	DEF_MAGIC_PROL_MASTER("dsub", cmd_byte, 1, NULL, {}, 
	{

		double temp  = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);
		temp = temp2 - temp;
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 18)
{

	DEF_MAGIC_PROL_MASTER("hlt", cmd_byte, 1, NULL, {}, 
	{

	}, true, file_byte_stack.size)	
}
else if (cmd_byte == 19)
{

	DEF_MAGIC_PROL_MASTER("tol", cmd_byte, 1, NULL, {},
	{

		double temp = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = (long long)temp;
		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 20)
{

	DEF_MAGIC_PROL_MASTER("tod", cmd_byte, 1, NULL, {},
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = (double)temp;
		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 21)
{

	DEF_MAGIC_PROL_MASTER("jmp", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

	}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
}
else if (cmd_byte == 22)
{

	DEF_MAGIC_PROL_MASTER("call", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		uint16_t temp = _i + 3;
		push_n_prol_stack(&cpu_ret_stack, &temp, 1);
	}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
}
else if (cmd_byte == 23)
{

	time_t temp = 0;
	time(&temp);
	char *temp2 = asctime(localtime(&temp));
	temp2[3] = '\0';

	if (strcmp(temp2, "Mon") == 0)
	{

		DEF_MAGIC_PROL_MASTER("jm", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("jm", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 24)
{

	if (cmp_res == -1)
	{

		DEF_MAGIC_PROL_MASTER("jb", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("jb", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 25)
{

	if (cmp_res == -1 || cmp_res == 0)
	{

		DEF_MAGIC_PROL_MASTER("jbe", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("jbe", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 26)
{

	if (cmp_res == 0)
	{

		DEF_MAGIC_PROL_MASTER("je", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("je", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 27)
{

	if (cmp_res != 0)
	{

		DEF_MAGIC_PROL_MASTER("jne", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("jne", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 28)
{

	if (cmp_res == 1)
	{

		DEF_MAGIC_PROL_MASTER("ja", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("ja", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 29)
{

	if (cmp_res == -1 || cmp_res == 0)
	{

		DEF_MAGIC_PROL_MASTER("jae", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, true, (int)(*(uint16_t*)get_prol_stack(&file_byte_stack, _i + 1)))
	}
	else
	{

		DEF_MAGIC_PROL_MASTER("jae", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
		{

		}, false, 0)
	}
}
else if (cmd_byte == 30)
{

	DEF_MAGIC_PROL_MASTER("dcmp", cmd_byte, 1, NULL, {},
	{

		double temp = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		double temp2 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);

		double temp3 = temp2 - temp;
		if (temp3 < -0.0000001)
			cmp_res = -1;
		else if (temp3 > 0.0000001)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)
}
else if (cmd_byte == 31)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 1, NULL, {},
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 16);

		long long temp3 = temp2 - temp;
		if (temp3 < 0)
			cmp_res = -1;
		else if (temp3 > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)
}
else if (cmd_byte == 32)
{

	DEF_MAGIC_PROL_MASTER("ret", cmd_byte, 1, NULL, {},
	{

		ret_temp = *(uint16_t*)get_prol_stack(&cpu_ret_stack, cpu_ret_stack.size - 1);
		pop_prol_stack(&cpu_ret_stack);
	}, true, (int)ret_temp)
}
else if (cmd_byte == 33)
{

	DEF_MAGIC_PROL_MASTER("inc", cmd_byte, 1, NULL, {},
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		temp++;
		pop_n_prol_stack(&cpu_byte_stack, 8);
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 34)
{

	DEF_MAGIC_PROL_MASTER("dec", cmd_byte, 1, NULL, {},
	{

		long long temp = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);
		temp--;
		pop_n_prol_stack(&cpu_byte_stack, 8);
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 35)
{

	DEF_MAGIC_PROL_MASTER("lin", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = 0;
		scanf("%lld", &temp);

		unsigned char temp2 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp2--;

		memcpy(regs[temp2], &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 36)
{

	DEF_MAGIC_PROL_MASTER("din", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		double temp = 0;
		scanf("%lf", &temp);

		unsigned char temp2 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp2--;

		memcpy(regs[temp2], &temp, 8);
	}, false, 0)
}
else if (cmd_byte == 37)
{

	DEF_MAGIC_PROL_MASTER("lout", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		printf("%lld\n", *(long long*)regs[temp]);
	}, false, 0)
}
else if (cmd_byte == 38)
{

	DEF_MAGIC_PROL_MASTER("dout", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		printf("%lf\n", *(double*)regs[temp]);
	}, false, 0)
}
else if (cmd_byte == 39)
{

	DEF_MAGIC_PROL_MASTER("push", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		push_n_prol_stack(&cpu_byte_stack, regs[temp], 8);
	}, false, 0)
}
else if (cmd_byte == 40)
{

	DEF_MAGIC_PROL_MASTER("pop", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		memcpy(regs[temp], get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8), 8);
		pop_n_prol_stack(&cpu_byte_stack, 8);
	}, false, 0)
}
else if (cmd_byte == 41)
{

	DEF_MAGIC_PROL_MASTER("sqrt", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		temp2 = sqrt(temp2);

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 42)
{

	DEF_MAGIC_PROL_MASTER("lsqr", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		temp2 = temp2 * temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 43)
{

	DEF_MAGIC_PROL_MASTER("dsqr", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		temp2 = temp2 * temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 44)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 += temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 45)
{

	DEF_MAGIC_PROL_MASTER("dadd", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 += temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 46)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 *= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 47)
{

	DEF_MAGIC_PROL_MASTER("dmul", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 *= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 48)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 = temp3 / temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 49)
{

	DEF_MAGIC_PROL_MASTER("ddiv", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 = temp3 / temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 50)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 = temp3 % temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 51)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 = temp3 - temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 52)
{

	DEF_MAGIC_PROL_MASTER("dsub", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp2 = temp3 - temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);
	}, false, 0)
}
else if (cmd_byte == 53)
{

	DEF_MAGIC_PROL_MASTER("tol", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp2 = *(double*)regs[temp];

		long long temp3 = (long long)temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
	}, false, 0)
}
else if (cmd_byte == 54)
{

	DEF_MAGIC_PROL_MASTER("tod", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp2 = *(long long*)regs[temp];

		double temp3 = (double)temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
	}, false, 0)
}
else if (cmd_byte == 55)
{

	DEF_MAGIC_PROL_MASTER("dcmp", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)regs[temp];
		double temp2 = *(double*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		double temp3 = temp2 - temp1;
		if (temp3 < -0.0000001)
			cmp_res = -1;
		else if (temp3 > 0.0000001)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)
}
else if (cmd_byte == 56)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		long long temp3 = temp2 - temp1;
		if (temp3 < 0)
			cmp_res = -1;
		else if (temp3 > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)
}
else if (cmd_byte == 57)
{

	DEF_MAGIC_PROL_MASTER("inc", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		temp1++;
		memcpy(regs[temp], &temp1, 8);

	}, false, 0)
}
else if (cmd_byte == 58)
{

	DEF_MAGIC_PROL_MASTER("dec", cmd_byte, 2, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		temp1--;
		memcpy(regs[temp], &temp1, 8);

	}, false, 0)
}
else if (cmd_byte == 59)
{

	DEF_MAGIC_PROL_MASTER("sqrt", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		temp2 = sqrt(temp2);

		memcpy(regs[temp1], &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 60)
{

	DEF_MAGIC_PROL_MASTER("lsqr", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		temp2 = temp2 * temp2;

		memcpy(regs[temp1], &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 61)
{

	DEF_MAGIC_PROL_MASTER("dsqr", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		temp2 = temp2 * temp2;

		memcpy(regs[temp1], &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 62)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];
		temp2 += temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 63)
{

	DEF_MAGIC_PROL_MASTER("dadd", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)regs[temp1];
		temp2 += temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 64)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];
		temp2 *= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 65)
{

	DEF_MAGIC_PROL_MASTER("dmul", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)regs[temp1];
		temp2 *= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 66)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];
		temp2 /= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 67)
{

	DEF_MAGIC_PROL_MASTER("ddiv", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)regs[temp1];
		temp2 /= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 68)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];
		temp2 %= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 69)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];
		temp2 -= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 70)
{

	DEF_MAGIC_PROL_MASTER("dsub", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)regs[temp1];
		temp2 -= temp3;

		push_n_prol_stack(&cpu_byte_stack, &temp2, 8);

	}, false, 0)	
}
else if (cmd_byte == 71)
{

	DEF_MAGIC_PROL_MASTER("tol", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		long long temp3 = (long long)temp2;

		memcpy(regs[temp1], &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 72)
{

	DEF_MAGIC_PROL_MASTER("tod", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		double temp3 = (double)temp2;

		memcpy(regs[temp1], &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 73)
{

	DEF_MAGIC_PROL_MASTER("dcmp", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		double temp2 = *(double*)regs[temp];
		double temp3 = *(double*)regs[temp1];

		double temp4 = temp2 - temp3;
		if (temp4 < -0.0000001)
			cmp_res = -1;
		else if (temp4 > 0.0000001)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)	
}
else if (cmd_byte == 74)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		long long temp2 = *(long long*)regs[temp];
		long long temp3 = *(long long*)regs[temp1];

		double temp4 = temp3 - temp2;
		if (temp4 < 0)
			cmp_res = -1;
		else if (temp4 > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)	
}
else if (cmd_byte == 75)
{

	DEF_MAGIC_PROL_MASTER("mov", cmd_byte, 3, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 2);
		temp1--;

		memcpy(regs[temp], regs[temp1], 8);
	}, false, 0)	
}
else if (cmd_byte == 76)
{

	DEF_MAGIC_PROL_MASTER("mov", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		memcpy(regs[temp], get_prol_stack(&file_byte_stack, _i + 2), 8);
	}, false, 0)	
}
else if (cmd_byte == 77)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp2 - temp1;
		if (temp3 < 0)
			cmp_res = -1;
		else if (temp3 > 0)
			cmp_res = 1;
		else
			cmp_res = 0;

	}, false, 0)	
}
else if (cmd_byte == 78)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp2 + temp1;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 79)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp2 * temp1;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 80)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp1 / temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 81)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp1 % temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 82)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		long long temp1 = *(long long*)regs[temp];
		long long temp2 = *(long long*)get_prol_stack(&file_byte_stack, _i + 2);

		long long temp3 = temp1 - temp2;

		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);

	}, false, 0)	
}
else if (cmd_byte == 83)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 9);
		temp1--;

		long long temp2 = *(long long*)regs[temp1];

		long long temp3 = temp2 - temp;
		if (temp3 < 0)
			cmp_res = -1;
		else if (temp3 > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;

	}, false, 0)
}
else if (cmd_byte == 84)
{

	DEF_MAGIC_PROL_MASTER("tod", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 9);
		temp1--;

		double temp3 = (double)temp;

		memcpy(regs[temp1], &temp3, 8);

	}, false, 0)
}
else if (cmd_byte == 85)
{

	DEF_MAGIC_PROL_MASTER("lout", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		printf("%lld\n", temp);
		fflush(stdout);

	}, false, 0)	
}
else if (cmd_byte == 86)
{

	DEF_MAGIC_PROL_MASTER("push", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 87)
{

	DEF_MAGIC_PROL_MASTER("lsqr", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);
		temp *= temp;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)
}
else if (cmd_byte == 88)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp += temp1;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 89)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp *= temp1;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 90)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp = temp1 / temp;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 91)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp = temp1 % temp;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 92)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp = temp1 - temp;

		push_n_prol_stack(&cpu_byte_stack, &temp, 8);

	}, false, 0)	
}
else if (cmd_byte == 93)
{

	DEF_MAGIC_PROL_MASTER("tod", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		double temp1 = (double)temp;

		push_n_prol_stack(&cpu_byte_stack, &temp1, 8);

	}, false, 0)	
}
else if (cmd_byte == 94)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 9, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&cpu_byte_stack, cpu_byte_stack.size - 8);

		temp = temp - temp1;
		if (temp < 0)
			cmp_res = -1;
		else if (temp > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;
		
	}, false, 0)	
}
else if (cmd_byte == 95)
{

	DEF_MAGIC_PROL_MASTER("lcmp", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp1 - temp;
		if (temp < 0)
			cmp_res = -1;
		else if (temp > 0)
			cmp_res = 1;
		else 
			cmp_res = 0;
		
	}, false, 0)	
}
else if (cmd_byte == 96)
{

	DEF_MAGIC_PROL_MASTER("ladd", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp1 + temp;
	
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 97)
{

	DEF_MAGIC_PROL_MASTER("lmul", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp1 * temp;
	
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 98)
{

	DEF_MAGIC_PROL_MASTER("ldiv", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp / temp1;
	
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 99)
{

	DEF_MAGIC_PROL_MASTER("lsub", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp - temp1;
	
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 100)
{

	DEF_MAGIC_PROL_MASTER("mod", cmd_byte, 17, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		long long temp = *(long long*)get_prol_stack(&file_byte_stack, _i + 1);

		long long temp1 = *(long long*)get_prol_stack(&file_byte_stack, _i + 9);

		temp = temp % temp1;
	
		push_n_prol_stack(&cpu_byte_stack, &temp, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 101)
{

	DEF_MAGIC_PROL_MASTER("mov", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		memcpy(regs[temp], &temp1, 8);
		
	}, false, 0)
}
else if (cmd_byte == 102)
{

	DEF_MAGIC_PROL_MASTER("dcmp", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		double temp2 = *(double*)regs[temp];

		double temp3 = temp2 - temp1;
		if (temp3 < -0.0000001)
			cmp_res = -1;
		else if (temp3 > 0.0000001)
			cmp_res = 1;
		else 
			cmp_res = 0;
		
	}, false, 0)	
}
else if (cmd_byte == 103)
{

	DEF_MAGIC_PROL_MASTER("dadd", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		double temp2 = *(double*)regs[temp];

		double temp3 = temp1 + temp2;
		
		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 104)
{

	DEF_MAGIC_PROL_MASTER("dmul", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		double temp2 = *(double*)regs[temp];

		double temp3 = temp1 * temp2;
		
		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 105)
{

	DEF_MAGIC_PROL_MASTER("ddiv", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		double temp2 = *(double*)regs[temp];

		double temp3 = temp2 / temp1;
		
		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 106)
{

	DEF_MAGIC_PROL_MASTER("dsub", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		unsigned char temp = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 1);
		temp--;

		double temp1 = *(double*)get_prol_stack(&file_byte_stack, _i + 2);

		double temp2 = *(double*)regs[temp];

		double temp3 = temp2 - temp1;
		
		push_n_prol_stack(&cpu_byte_stack, &temp3, 8);
		
	}, false, 0)	
}
else if (cmd_byte == 107)
{

	DEF_MAGIC_PROL_MASTER("dcmp", cmd_byte, 10, get_prol_stack(&file_byte_stack, _i + 1), {},
	{

		double temp = *(double*)get_prol_stack(&file_byte_stack, _i + 1);

		unsigned char temp1 = *(unsigned char*)get_prol_stack(&file_byte_stack, _i + 9);
		temp1--;

		double temp2 = *(double*)regs[temp1];

		double temp3 = temp - temp2;
		if (temp3 < -0.0000001)
			cmp_res = -1;
		else if (temp3 > 0.0000001)
			cmp_res = 1;
		else cmp_res = 0;
		
	}, false, 0)	
}