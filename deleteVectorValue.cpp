vector<int>  v_ind;
v_ind.push_back(36);
v_ind.push_back(39);
v_ind.push_back(45);
//goal: delete Nr. 36 39 45 in vec_id
for (size_t ind = vec_id.size(); ind >=0; ind--)
{
  vec_id.erase(vec_id.begin()+v_ind[ind]);
}
//--> get an error: because size_t = 2 1 0 4294967295 4294967294
// correct use int instatt
// size_t = 2 1 0 -...
