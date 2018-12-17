bool resonator::empty()
{
    return firstElement==NULL;
}

void resonator::addElenent()
{
    optMtr *el= new(optMtr);
    if (empty())
    {
        el->previousElemtnt=NULL;
        el->nextElement=NULL;
        firstElement=el;
        lastElement=el;
    }
    else
    {
        lastElement->nextElement=el;
        el->previousElemtnt=lastElement;
        lastElement=el;
        el->nextElement=NULL;
    }
    nEl++;
}

void resonator::deletAllElements()
{
    optMtr *ptr=lastElement;
    optMtr *previousPtr;
    while (!empty())
    {
        previousPtr=ptr->previousElemtnt;
        if (ptr==firstElement) firstElement = NULL;
        //printf("delet element \"%i\"\n",ptr->name);
        delete (ptr);
        ptr=previousPtr;
    }
}

void resonator::deletElement(int n)//переписать
{
    optMtr *ptr=ptrEl(n);
    if (ptr==firstElement) firstElement=ptr->nextElement;
    if (ptr==lastElement) lastElement=ptr->previousElemtnt;
    ptr->previousElemtnt->nextElement = ptr->nextElement;
    ptr->nextElement->previousElemtnt = ptr->previousElemtnt;
    if (firstElement==lastElement) firstElement = NULL;
    delete (ptr);
}

optMtr *resonator::ptrEl(int n)
{
    //qDebug()<<"ptrEl"<<n;
    optMtr *ptr=firstElement;
    for (int i=1;i<n;i++)
        ptr=ptr->nextElement;
    //qDebug()<<"ptrEl end"<<n;
    return ptr;

}

