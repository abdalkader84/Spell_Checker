struct node
{
	String key;
	String value;
	node* next;
};
class hash_table
{
private:
	node** tbl;
	int nItems;
	int ar_size;
	int hash_func(String key);
	bool isprim(int x);
protected:
public:
	void insert(String key, String value);
	void remove(String key );
	String find(String key);
	hash_table(int nItems);
	~hash_table();
};
bool hash_table::isprim(int x)
{
	for (int l = x - 1; l >= 2; l--)
	{
		if (x % l == 0)
		{
			return false;
		}
	}
	return true;
}
hash_table::hash_table(int _nItems)
{
	tbl = NULL;
	nItems =_nItems;
	int startsiz = 0;
	startsiz = _nItems * 100 / 70;
	while (isprim(startsiz) != true) { startsiz++; }
	ar_size = startsiz;
	tbl = new node * [ar_size];
	for (int i = 0; i < ar_size; i++)
	{
		tbl[i] = NULL;
	}
}
hash_table::~hash_table()
{
	for (int i = 0; i < ar_size; i++)
	{
		node* p = tbl[i];
		node* pp = p;
		while (p != NULL)
		{
			p = p->next;
			delete pp;
			pp = p;
		}
	}
	delete tbl;
}

int hash_table::hash_func(String key)
{
	int hash = 0;
	for (int i = 1; i <= key.Length(); i++)
	{
		char ch = (key[i] - 0);
		hash = (hash * 256 + ch) % ar_size;
	}
	return hash;
}
String hash_table::find(String key)
{
	int idx = hash_func(key);
	node* _ptn = tbl[idx];
	String res="";
	while (_ptn != NULL)
	{
		if (_ptn->key == key)
		{
			res = _ptn->value;
			break;
		}
		else
		{
			_ptn = _ptn->next;
		}
	}
	return res;
}
void hash_table::insert(String key, String value)
{
	node* _tn = new node;
	_tn->key = key;
	_tn->value = value;
	_tn->next = NULL;

	int idx = hash_func(key);
	if ( tbl[idx] == NULL)
	{
		tbl[idx] = _tn;
	}
	else
	{
		bool is_new = true;
		node* _ptn = tbl[idx];


		while (_ptn->next != NULL)
		{
			if (_ptn->key == key)
			{
				_ptn->value = value;
				is_new = false;
				break;
			}
			else
			{
				_ptn = _ptn->next;
			}
		}
		if (_ptn->next == NULL)
		{
			if (_ptn->key == key)
			{
				_ptn->value = value;
				is_new = false;
			}
		}
		if (is_new == true)
		{
			_ptn->next = _tn;
		}
	}
}
void hash_table::remove(String key)
{
	int idx = hash_func(key);

	if (tbl[idx]->key == key)
	{
		tbl[idx] = tbl[idx]->next;
	}
	else
	{
		node* _tn = tbl[idx];
		node* _ptn = _tn;
		while (_tn->key != key && _tn != NULL)
		{
			_ptn = _tn;
			_tn = _tn->next;
		}
		if (_tn->key == key)
		{
			_ptn->next = _tn->next;
			delete _tn;
		}
	}
}

