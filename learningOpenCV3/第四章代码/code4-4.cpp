template <class T> void print_matrix(const cv::SparseMat_<T>* sm)
{
	cv::SparseMatConstIterator_<T> it = sm->begin();
	cv::SparseMatConstIterator_<T> it_end = sm->end();

	for (; it != it_end; ++it)
	{
		const typename cv::SparseMat_<T>::Node* node = it.node();
		cout << "(" << node->idx[0] << ", " << node->idx[1] << " ) = " << *it << endl;
	}
}
void calling_function1(void)
{
	//...
	cv::SparseMat_<float> sm(ndim, size);
	//...
	print_matrix<float>(&sm);
}

void calling_function2(void)
{
	//...
	cv::SparseMat sm(ndim, size, CV_32F);
	//...
	print_matrix<float>((cv::SparseMat_<float>*) & sm);
}