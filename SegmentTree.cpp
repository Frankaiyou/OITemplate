struct SegmentTreeTypeAdd
{
	struct node
	{
		int l,r,w,f;//left,right,weight,flag;
		node()
		{
			l=r=w=f=0;
		}
	} tree[400001];
	inline void build(int k,int ll,int rr)//����
	{
		//�÷���build(�ڵ���,����,�Һ���);
		//��ʼ����build(1,1,�ڵ����);
		tree[k].l=ll,tree[k].r=rr;
		if(tree[k].l==tree[k].r)
		{
			scanf("%d",&tree[k].w);
			return;
		}
		int m=(ll+rr)/2;
		build(k*2,ll,m);
		build(k*2+1,m+1,rr);
		tree[k].w=tree[k*2].w+tree[k*2+1].w;
	}
	inline void down(int k)//����´�
	{
		//�÷���down(��Ҫ�´���ǵĸ��ڵ�);
		tree[k*2].f+=tree[k].f;
		tree[k*2+1].f+=tree[k].f;
		tree[k*2].w+=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
		tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
		tree[k].f=0;
	}
	inline void ask_point(int k)//�����ѯ
	{
		//�÷���ask_point(��Ҫ��ѯ�ĵ�ı��);
		if(tree[k].l==tree[k].r)
		{
			ans=tree[k].w;
			return ;
		}
		if(tree[k].f) down(k);
		int m=(tree[k].l+tree[k].r)/2;
		if(x<=m) ask_point(k*2);
		else ask_point(k*2+1);
	}
	inline void change_point(int k)//�����޸�
	{
		//�÷���change_point(��Ҫ�޸ĵĵ�ı��);
		if(tree[k].l==tree[k].r)
		{
			tree[k].w+=y;
			return;
		}
		int m=(tree[k].l+tree[k].r)/2;
		if(x<=m) change_point(k*2);
		else change_point(k*2+1);
		tree[k].w=tree[k*2].w+tree[k*2+1].w;
	}
	inline void ask_interval(int k)//�����ѯ
	{
		//�÷���ask_iterval(��ѯ���);
		if(tree[k].l>=a&&tree[k].r<=b)//a��bΪ��Ҫ��ѯ������
		{
			ans+=tree[k].w;
			return;
		}
		if(tree[k].f) down(k);
		int m=(tree[k].l+tree[k].r)/2;
		if(a<=m) ask_interval(k*2);
		if(b>m) ask_interval(k*2+1);
	}
	inline void change_interval(int k)//�����޸�
	{
		//�÷���change_interval(�޸����);
		if(tree[k].l>=a&&tree[k].r<=b)//a��bΪ��Ҫ�޸ĵ�����
		{
			tree[k].w+=(tree[k].r-tree[k].l+1)*y;
			tree[k].f+=y;
			return;
		}
		if(tree[k].f) down(k);//���к��ӽڵ㣬�´����
		int m=(tree[k].l+tree[k].r)/2;//���ִ���
		if(a<=m) change_interval(k*2);
		if(b>m) change_interval(k*2+1);
		tree[k].w=tree[k*2].w+tree[k*2+1].w;
	}
};