/* ����ģʽ(Singleton)
 * �ص㣺(1) ʹ�õ���������ֻ�ܲ���һ��ʵ����
 *       (2) �����ṩ�ӿڸ������ã����Ҳֻ��ͨ�����øýӿ����õ�ʵ����
 * ʹ�ó�������������������������ж��ڸ�����ֻ����һ��ʵ������ʱ��
 *           ��������������������н��̵�manager��
 * �ô���(1) ��֤���û��������������������ϵ�ʵ����
 *       (2) ָ����һ���ڴ棬��ʡ���ڴ棬�������ڴ���Ƭ��
 */

#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int nData;
} DataType;

static DataType s_instance3;
static DataType* s_pInstance4 = NULL;

DataType* GetInstance();
DataType* GetInstance2();
DataType* GetInstance3();
DataType* GetInstance4();

int main()
{
    DataType* pInstance = NULL;
    DataType* pInstance2 = NULL;
    DataType* pInstance3 = NULL;
    DataType* pInstance4 = NULL;

    pInstance = GetInstance();
    pInstance2 = GetInstance2();
    pInstance3 = GetInstance3();
    pInstance4 = GetInstance4();

    if (NULL != pInstance2)
    {
        free(pInstance2);
    }
    if (NULL != pInstance2)
    {
        free(pInstance4);
    }

    return 0;
}

DataType* GetInstance()
{
    static DataType instance;
    
    return &instance;
}

DataType* GetInstance2()
{
    static DataType* pInstance2 = NULL;

    if (NULL == pInstance2)
    {
        pInstance2 = (DataType*)malloc(sizeof(DataType));
    }
    return pInstance2;
}

DataType* GetInstance3()
{
    return &s_instance3;
}

DataType* GetInstance4()
{
    if (NULL == s_pInstance4)
    {
        s_pInstance4 = (DataType*)malloc(sizeof(DataType));
    }
    return s_pInstance4;
}
